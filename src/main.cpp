#include <Arduino.h>
#include <PubSubClient.h>  
#include "WiFi.h"


/////////////////////////////////////////////////////////////////////////// Funktionsprototypen
void loop                       ();
void wifi_setup                 ();
void callback                   (char* topic, byte* payload, unsigned int length);
void reconnect                       ();

/////////////////////////////////////////////////////////////////////////// Kartendaten 
const char* kartenID = "24Relaiskarte_Wohnzimmer";

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
IPAddress local_IP(192, 168, 13, 55);
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


/////////////////////////////////////////////////////////////////////////// SETUP
void setup() {

  // Serielle Kommunikation starten
  Serial.begin(115200);

// Wifi setup
wifi_setup();

// MQTT Broker
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

}

/////////////////////////////////////////////////////////////////////////// LOOP
void loop() {

  // MQTT Server kontaktieren
  if (!client.connected()) {
  reconnect();
  }
  client.loop();

  // mqtt Testnachricht senden
  client.publish("Solarpanel/001/", "test");

  Serial.print("Millis Loop : ");
  Serial.println(millis());

delay(500);
}
