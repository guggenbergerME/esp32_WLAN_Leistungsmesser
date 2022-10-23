#include <Arduino.h>
#include <PubSubClient.h>  
#include "WiFi.h"
 #include <SPI.h>
#include <Adafruit_ADS1X15.h> 

/////////////////////////////////////////////////////////////////////////// ADS1115
Adafruit_ADS1115 ads;
#define ADS_I2C_ADDR 0x48
//const float multiplier = 0.01F; // ADS1115-Multiplikator bei einf. Verstärkung

// Strom am Shunt messen
int adc0;                     // Messwert an Kanal 0 des ADS1115 - Strom
float Strom_Panel = 0.0;
float GAIN_faktor_Strom = 0.03125; 
float umrechnung_faktor_messert_strom = 0.0002;

// Spannung der Panelen messen über Spannungsteiler MAX 100V
int adc1;                                           // Messwert an Kanal 1 des ADS1115 - Spannung
float Voltage_Panel                    = 0.0;
float GAIN_faktor_Spannung              = 0.185;
int umrechnung_faktor_messert_spannung = 1925;

//SCL an GPIO 22 - SDA an GPIO 21

/////////////////////////////////////////////////////////////////////////// Funktionsprototypen
void loop                       ();
void wifi_setup                 ();
void callback                   (char* topic, byte* payload, unsigned int length);
void reconnect                  ();
void messen_strom               ();
void messen_spannung            ();

/////////////////////////////////////////////////////////////////////////// Systemvariable
float max_V_solar = 95; // Maximale Stringspannung zum messen

/////////////////////////////////////////////////////////////////////////// ADC Variablen
const int adc_V = 34; //ADC1_6 - FSpannungsteiler bis 100V 
const int adc_A = 35; //ADC1_7 - Stromshunt 

/////////////////////////////////////////////////////////////////////////// Systemvariablen setzen
int adc_sensor_V, adc_sensor_A;
int ausgabe_volt, ausgabe_ampere;

/////////////////////////////////////////////////////////////////////////// Schleifen verwalten
unsigned long previousMillis_Spannung_messen = 0; // Spannung Messen
unsigned long interval_Spannung_messen = 1500; 

unsigned long previousMillis_Strom_messen = 0; // Strom Messen
unsigned long interval_Strom_messen = 1500; 

/////////////////////////////////////////////////////////////////////////// Kartendaten 
const char* kartenID = "Solarmodul_001";

/////////////////////////////////////////////////////////////////////////// MQTT 
WiFiClient espClient;
PubSubClient client(espClient);

const char* mqtt_server = "192.168.150.1";

/////////////////////////////////////////////////////////////////////////// SETUP - Wifi
void wifi_setup() {

// WiFi Zugangsdaten
const char* WIFI_SSID = "GuggenbergerLinux";
const char* WIFI_PASS = "Isabelle2014samira";

// Static IP
IPAddress local_IP(192, 168, 13, 51);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 0, 0, 0);  
IPAddress dns(192, 168, 1, 1); 

// Verbindung zu SSID
Serial.print("Verbindung zu SSID - ");
Serial.println(WIFI_SSID); 

// IP zuweisen
if (!WiFi.config(local_IP, gateway, subnet, dns)) {
   Serial.println("STA fehlerhaft!");
  }


// WiFI Modus setzen
WiFi.mode(WIFI_OFF);
WiFi.disconnect();
delay(100);

WiFi.begin(WIFI_SSID, WIFI_PASS);
Serial.println("Verbindung aufbauen ...");

while (WiFi.status() != WL_CONNECTED) {

  if (WiFi.status() == WL_CONNECT_FAILED) {
     Serial.println("Keine Verbindung zum SSID möglich : ");
     Serial.println();
     Serial.print("SSID: ");
     Serial.println(WIFI_SSID);
     Serial.print("Passwort: ");
     Serial.println(WIFI_PASS);
     Serial.println();
    }
  delay(2000);
}
    Serial.println("");
    Serial.println("Mit Wifi verbunden");
    Serial.println("IP Adresse: ");
    Serial.println(WiFi.localIP());

}

//****************************************************************************************** VOID mqtt reconnected
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Baue Verbindung zum mqtt Server auf. IP: ");
    // Attempt to connect
    if (client.connect(kartenID,"zugang1","43b4134735")) {
      Serial.println("connected");
////////////////////////////////////////////////////////////////////////////////// SUBSCRIBE Eintraege
      client.subscribe("relais_licht_wohnzimmer_1_0/IN");

    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

/////////////////////////////////////////////////////////////////////////// MQTT callback
void callback(char* topic, byte* payload, unsigned int length) {

  /////////////////////////////////////////////////////////////////////////// Relais 0
      if (strcmp(topic,"relais_licht_wohnzimmer_1_0/IN")==0) {

          // ON und OFF Funktion auslesen
          if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                  Serial.println("relais_0 -> AN");

                }

          if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                  Serial.println("relais_0 -> AUS");

                }
        } 
  
}

/////////////////////////////////////////////////////////////////////////// Messen Strom
void messen_strom() {
// Strom per Shunt messen 
ads.setGain(GAIN_FOUR);
  //client.publish("Solarpanel/001/spannung/", "Spannung");

   Serial.println("Strom messen ");

int16_t adc0; // 16 bits ADC read of input A0
adc0 = ads.readADC_SingleEnded(0);
//Strom_Panel = (adc0 / GAIN_faktor_Strom) / umrechnung_faktor_messert_strom;
Strom_Panel = (adc0 / GAIN_faktor_Strom) * umrechnung_faktor_messert_strom;
//Voltage_Panel = adc1;


 Serial.print("Strom Panel : ");
 Serial.println(Strom_Panel);

}

/////////////////////////////////////////////////////////////////////////// Messen Spannung
void messen_spannung() {
  // Spannung über Spannungsteiler messen. Maximal U max_V_solar
ads.setGain(GAIN_ONE);
int16_t adc1; // 16 bits ADC read of input A0
adc1 = ads.readADC_SingleEnded(1);
Voltage_Panel = (adc1 / GAIN_faktor_Spannung) / umrechnung_faktor_messert_spannung;
//Voltage_Panel = adc1;


 Serial.print("Volt Panel : ");
 Serial.println(Voltage_Panel);

}

/////////////////////////////////////////////////////////////////////////// SETUP
void setup() {

  // Serielle Kommunikation starten
  Serial.begin(115200);

// Wifi setup
wifi_setup();

// MQTT Broker
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

// ADS1115 Setup
  ads.begin(ADS_I2C_ADDR, &Wire);
  // Werte 1-fach verstärken (ESP32 liefert  max. 3,3V)
   

}

/////////////////////////////////////////////////////////////////////////// LOOP
void loop() {

  // MQTT Server kontaktieren
  if (!client.connected()) {
  reconnect();
  }
  client.loop();

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ Spannung messen
  if (millis() - previousMillis_Spannung_messen > interval_Spannung_messen) {
      previousMillis_Spannung_messen = millis(); 
      // Prüfen der Panelenspannung
      Serial.println("Panele Spannung messen");
      messen_spannung();
    }

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ Strom messen
  if (millis() - previousMillis_Strom_messen > interval_Strom_messen) {
      previousMillis_Strom_messen = millis(); 
      // Prüfen der Stromabgabe
      Serial.println("Panele Strom messen");
      messen_strom();
    }


}
