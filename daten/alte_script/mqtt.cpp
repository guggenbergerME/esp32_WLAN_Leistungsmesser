#include <Arduino.h>
#include <SPI.h>
#include <ESP8266WiFi.h> 
#include <PubSubClient.h>  
#include <ArduinoOTA.h>
#include <PCF8574.h>
#include "PCF8591.h" // https://github.com/overbog/PCF8591


//////////////////////////////////////////////////////////////////////////// PCF8574 Adresse
PCF8574 pcf8574_1(0x20);
PCF8574 pcf8574_2(0x21);
PCF8574 pcf8574_3(0x22);
PCF8574 pcf8574_4(0x24);
// SCL - D1
// SDA - D2
// pcf8574_1.digitalWrite(P, !LOW);
///////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////// Kartendaten 
const char* kartenID = "24Relaiskarte_Wohnzimmer";
///////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////// Intervall der Steuerung
unsigned long previousMillis_LOOP_schleife_1 = 0;
unsigned long interval_LOOP_schleife_1 = 60000; 

///////////////////////////////////////////////////////////////////////////


WiFiClient espClient;
PubSubClient client(espClient);

// Connect to the WiFi
const char* ssid = "GuggenbergerLinux";
const char* password = "Isabelle2014samira";
const char* mqtt_server = "192.168.150.1";


//****************************************************************************************** VOID mqtt callback
void callback(char* topic, byte* payload, unsigned int length) {
/////////////////////////////////////////////////////////////////////////// Relais ansprechen per MQTT

  /////////////////////////////////////////////////////////////////////////// Relais 0
      if (strcmp(topic,"relais_licht_wohnzimmer_1_0/IN")==0) {

          // ON und OFF Funktion auslesen
          if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                  Serial.println("relais_0 -> AN");
                  pcf8574_1.digitalWrite(P0, !HIGH);
                  client.publish("relais_licht_wohnzimmer_1_0/OUT","on");
                  delay(100);
                }

          if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                  Serial.println("relais_0 -> AUS");
                  pcf8574_1.digitalWrite(P0, !LOW);
                  client.publish("relais_licht_wohnzimmer_1_0/OUT","off");
                  delay(100);
                }
        } 
      
 

/////////////////////////////////////////////////////////////////////////// Relais 1
    if (strcmp(topic,"relais_licht_wohnzimmer_1_1/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_1 -> AN");
                 pcf8574_1.digitalWrite(P1, !HIGH);
                 client.publish("relais_licht_wohnzimmer_1_1/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_1 -> AUS");
                 pcf8574_1.digitalWrite(P1, !LOW);
                 client.publish("relais_licht_wohnzimmer_1_1/OUT","off");
                delay(100);
              }
      } 

/////////////////////////////////////////////////////////////////////////// Relais 2
    if (strcmp(topic,"relais_licht_wohnzimmer_1_2/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_2 -> AN");
                 pcf8574_1.digitalWrite(P2, !HIGH);
                 client.publish("relais_licht_wohnzimmer_1_2/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_2 -> AUS");
                 pcf8574_1.digitalWrite(P2, !LOW);
                 client.publish("relais_licht_wohnzimmer_1_2/OUT","off");
                delay(100);
              }
      } 

/////////////////////////////////////////////////////////////////////////// Relais 3
    if (strcmp(topic,"relais_licht_wohnzimmer_1_3/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_3 -> AN");
                 pcf8574_1.digitalWrite(P3, !HIGH);
                 client.publish("relais_licht_wohnzimmer_1_3/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_3 -> AUS");
                 pcf8574_1.digitalWrite(P3, !LOW);
                 client.publish("relais_licht_wohnzimmer_1_3/OUT","off");
                delay(100);
              }
      }

/////////////////////////////////////////////////////////////////////////// Relais 4
    if (strcmp(topic,"relais_licht_wohnzimmer_1_4/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_4 -> AN");
                 pcf8574_1.digitalWrite(P4, !HIGH);
                 client.publish("relais_licht_wohnzimmer_1_4/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_4 -> AUS");
                 pcf8574_1.digitalWrite(P4, !LOW);
                 client.publish("relais_licht_wohnzimmer_1_4/OUT","off");
                delay(100);
              }
      } 
      
/////////////////////////////////////////////////////////////////////////// Relais 5
    if (strcmp(topic,"relais_licht_wohnzimmer_1_5/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_5 -> AN");
                 pcf8574_1.digitalWrite(P5, !HIGH);
                 client.publish("relais_licht_wohnzimmer_1_5/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_5 -> AUS");
                 pcf8574_1.digitalWrite(P5, !LOW);
                 client.publish("relais_licht_wohnzimmer_1_5/OUT","off");
                delay(100);
              }
      } 
      
 /////////////////////////////////////////////////////////////////////////// Relais 6
    if (strcmp(topic,"relais_licht_wohnzimmer_1_6/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_6 -> AN");
                 pcf8574_1.digitalWrite(P6, !HIGH);
                 client.publish("relais_licht_wohnzimmer_1_6/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_6 -> AUS");
                 pcf8574_1.digitalWrite(P6, !LOW);
                 client.publish("relais_licht_wohnzimmer_1_6/OUT","off");
                delay(100);
              }
      } 
      
  /////////////////////////////////////////////////////////////////////////// Relais 7
    if (strcmp(topic,"relais_licht_wohnzimmer_1_7/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_7 -> AN");
                 pcf8574_1.digitalWrite(P7, !HIGH);
                 client.publish("relais_licht_wohnzimmer_1_7/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_7 -> AUS");
                 pcf8574_1.digitalWrite(P7, !LOW);
                 client.publish("relais_licht_wohnzimmer_1_7/OUT","off");
                delay(100);
              }
      } 
      
//************************************************************************************************** RELAISKARTE 2
              
/////////////////////////////////////////////////////////////////////////// Relais 0
    if (strcmp(topic,"relais_licht_wohnzimmer_2_0/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_2_0 -> AN");
                 pcf8574_2.digitalWrite(P0, !HIGH);
                 client.publish("relais_licht_wohnzimmer_2_0/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_2_0 -> AUS");
                 pcf8574_2.digitalWrite(P0, !LOW);
                 client.publish("relais_licht_wohnzimmer_2_0/OUT","off");
                delay(100);
              }
      } 

/////////////////////////////////////////////////////////////////////////// Relais 1
    if (strcmp(topic,"relais_licht_wohnzimmer_2_1/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_2_1 -> AN");
                 pcf8574_2.digitalWrite(P1, !HIGH);
                 client.publish("relais_licht_wohnzimmer_2_1/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_2_1 -> AUS");
                 pcf8574_2.digitalWrite(P1, !LOW);
                 client.publish("relais_licht_wohnzimmer_2_1/OUT","off");
                delay(100);
              }
      } 
      
/////////////////////////////////////////////////////////////////////////// Relais 2
    if (strcmp(topic,"relais_licht_wohnzimmer_2_2/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_2_2 -> AN");
                 pcf8574_2.digitalWrite(P2, !HIGH);
                 client.publish("relais_licht_wohnzimmer_2_2/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_2_2 -> AUS");
                 pcf8574_2.digitalWrite(P2, !LOW);
                 client.publish("relais_licht_wohnzimmer_2_2/OUT","off");
                delay(100);
              }
      } 
      
 /////////////////////////////////////////////////////////////////////////// Relais 3
    if (strcmp(topic,"relais_licht_wohnzimmer_2_3/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_2_3 -> AN");
                 pcf8574_2.digitalWrite(P3, !HIGH);
                 client.publish("relais_licht_wohnzimmer_2_3/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_2_3 -> AUS");
                 pcf8574_2.digitalWrite(P3, !LOW);
                 client.publish("relais_licht_wohnzimmer_2_3/OUT","off");
                delay(100);
              }
      } 
      
/////////////////////////////////////////////////////////////////////////// Relais 4
    if (strcmp(topic,"relais_licht_wohnzimmer_2_4/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_2_4 -> AN");
                 pcf8574_2.digitalWrite(P4, !HIGH);
                 client.publish("relais_licht_wohnzimmer_2_4/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_2_4 -> AUS");
                 pcf8574_2.digitalWrite(P4, !LOW);
                 client.publish("relais_licht_wohnzimmer_2_4/OUT","off");
                delay(100);
              }
      } 
      

/////////////////////////////////////////////////////////////////////////// Relais 5
    if (strcmp(topic,"relais_licht_wohnzimmer_2_5/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_2_5 -> AN");
                 pcf8574_2.digitalWrite(P5, !HIGH);
                 client.publish("relais_licht_wohnzimmer_2_5/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_2_5 -> AUS");
                 pcf8574_2.digitalWrite(P5, !LOW);
                 client.publish("relais_licht_wohnzimmer_2_5/OUT","off");
                delay(100);
              }
      } 
      
/////////////////////////////////////////////////////////////////////////// Relais 6
    if (strcmp(topic,"relais_licht_wohnzimmer_2_6/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_2_6 -> AN");
                 pcf8574_2.digitalWrite(P6, !HIGH);
                 client.publish("relais_licht_wohnzimmer_2_6/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_2_6 -> AUS");
                 pcf8574_2.digitalWrite(P6, !LOW);
                 client.publish("relais_licht_wohnzimmer_2_6/OUT","off");
                delay(100);
              }
      } 
      
/////////////////////////////////////////////////////////////////////////// Relais 7
    if (strcmp(topic,"relais_licht_wohnzimmer_2_7/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_2_7 -> AN");
                 pcf8574_2.digitalWrite(P7, !HIGH);
                 client.publish("relais_licht_wohnzimmer_2_7/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_2_7 -> AUS");
                 pcf8574_2.digitalWrite(P7, !LOW);
                 client.publish("relais_licht_wohnzimmer_2_7/OUT","off");
                delay(100);
              }
      } 
      
 //************************************************************************************************** RELAISKARTE 3

 /////////////////////////////////////////////////////////////////////////// Relais 0
    if (strcmp(topic,"relais_licht_wohnzimmer_3_0/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_3_0 -> AN");
                 pcf8574_3.digitalWrite(P0, !HIGH);
                 client.publish("relais_licht_wohnzimmer_3_0/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_3_0 -> AUS");
                 pcf8574_3.digitalWrite(P0, !LOW);
                 client.publish("relais_licht_wohnzimmer_3_0/OUT","off");
                delay(100);
              }
      } 
      
/////////////////////////////////////////////////////////////////////////// Relais 1
    if (strcmp(topic,"relais_licht_wohnzimmer_3_1/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_3_1 -> AN");
                 pcf8574_3.digitalWrite(P1, !HIGH);
                 client.publish("relais_licht_wohnzimmer_3_1/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_3_1 -> AUS");
                 pcf8574_3.digitalWrite(P1, !LOW);
                 client.publish("relais_licht_wohnzimmer_3_1/OUT","off");
                delay(100);
              }
      } 
      
/////////////////////////////////////////////////////////////////////////// Relais 2
    if (strcmp(topic,"relais_licht_wohnzimmer_3_2/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_3_2 -> AN");
                 pcf8574_3.digitalWrite(P2, !HIGH);
                 client.publish("relais_licht_wohnzimmer_3_2/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_3_2 -> AUS");
                 pcf8574_3.digitalWrite(P2, !LOW);
                 client.publish("relais_licht_wohnzimmer_3_2/OUT","off");
                delay(100);
              }
      } 
      
 /////////////////////////////////////////////////////////////////////////// Relais 3
    if (strcmp(topic,"relais_licht_wohnzimmer_3_3/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_3_3 -> AN");
                 pcf8574_3.digitalWrite(P3, !HIGH);
                 client.publish("relais_licht_wohnzimmer_3_3/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_3_3 -> AUS");
                 pcf8574_3.digitalWrite(P3, !LOW);
                 client.publish("relais_licht_wohnzimmer_3_3/OUT","off");
                delay(100);
              }
      } 
      
/////////////////////////////////////////////////////////////////////////// Relais 4
    if (strcmp(topic,"relais_licht_wohnzimmer_3_4/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_3_4 -> AN");
                 pcf8574_3.digitalWrite(P4, !HIGH);
                 client.publish("relais_licht_wohnzimmer_3_4/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_3_4 -> AUS");
                 pcf8574_3.digitalWrite(P4, !LOW);
                 client.publish("relais_licht_wohnzimmer_3_4/OUT","off");
                delay(100);
              }
      } 
      
/////////////////////////////////////////////////////////////////////////// Relais 5
    if (strcmp(topic,"relais_licht_wohnzimmer_3_5/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_3_5 -> AN");
                 pcf8574_3.digitalWrite(P5, !HIGH);
                 client.publish("relais_licht_wohnzimmer_3_5/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_3_5 -> AUS");
                 pcf8574_3.digitalWrite(P5, !LOW);
                 client.publish("relais_licht_wohnzimmer_3_5/OUT","off");
                delay(100);
              }
      } 
      
 /////////////////////////////////////////////////////////////////////////// Relais 6
    if (strcmp(topic,"relais_licht_wohnzimmer_3_6/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_3_6 -> AN");
                 pcf8574_3.digitalWrite(P6, !HIGH);
                 client.publish("relais_licht_wohnzimmer_3_6/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_3_6 -> AUS");
                 pcf8574_3.digitalWrite(P6, !LOW);
                 client.publish("relais_licht_wohnzimmer_3_6/OUT","off");
                delay(100);
              }
      } 
      
/////////////////////////////////////////////////////////////////////////// Relais 7
    if (strcmp(topic,"relais_licht_wohnzimmer_3_7/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_3_7 -> AN");
                 pcf8574_3.digitalWrite(P7, !HIGH);
                 client.publish("relais_licht_wohnzimmer_3_7/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_3_7 -> AUS");
                 pcf8574_3.digitalWrite(P7, !LOW);
                 client.publish("relais_licht_wohnzimmer_3_7/OUT","off");
                delay(100);
              }
      } 

/////////////////////////////////////////////////////////////////////////// Bank 4 - Relais 0
    if (strcmp(topic,"relais_licht_flur_1_0/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_0 -> AN");
                 pcf8574_4.digitalWrite(P0, !HIGH);
                 client.publish("relais_licht_flur_1_0/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_0 -> AUS");
                 pcf8574_4.digitalWrite(P0, !LOW);
                 client.publish("relais_licht_flur_1_0/OUT","off");
                delay(100);
              }
      }
      
/////////////////////////////////////////////////////////////////////////// Bank 4 - Relais 1
    if (strcmp(topic,"relais_licht_flur_1_1/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_1 -> AN");
                 pcf8574_4.digitalWrite(P1, !HIGH);
                 client.publish("relais_licht_flur_1_1/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_1 -> AUS");
                 pcf8574_4.digitalWrite(P1, !LOW);
                 client.publish("relais_licht_flur_1_1/OUT","off");
                delay(100);
              }
      }
      
/////////////////////////////////////////////////////////////////////////// Bank 4 - Relais 2
    if (strcmp(topic,"relais_licht_flur_1_2/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_2 -> AN");
                 pcf8574_4.digitalWrite(P2, !HIGH);
                 client.publish("relais_licht_flur_1_2/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_2 -> AUS");
                 pcf8574_4.digitalWrite(P2, !LOW);
                 client.publish("relais_licht_flur_1_2/OUT","off");
                delay(100);
              }
      }
      
/////////////////////////////////////////////////////////////////////////// Bank 4 - Relais 3
    if (strcmp(topic,"relais_licht_flur_1_3/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_3 -> AN");
                 pcf8574_4.digitalWrite(P3, !HIGH);
                 client.publish("relais_licht_flur_1_3/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_3 -> AUS");
                 pcf8574_4.digitalWrite(P3, !LOW);
                 client.publish("relais_licht_flur_1_3/OUT","off");
                delay(100);
              }
      }
      
/////////////////////////////////////////////////////////////////////////// Bank 4 - Relais 4
    if (strcmp(topic,"relais_licht_flur_1_4/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_4 -> AN");
                 pcf8574_4.digitalWrite(P4, !HIGH);
                 client.publish("relais_licht_flur_1_4/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_4 -> AUS");
                 pcf8574_4.digitalWrite(P4, !LOW);
                 client.publish("relais_licht_flur_1_4/OUT","off");
                delay(100);
              }
      }
      
/////////////////////////////////////////////////////////////////////////// Bank 4 - Relais 5
    if (strcmp(topic,"relais_licht_flur_1_5/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_5 -> AN");
                 pcf8574_4.digitalWrite(P5, !HIGH);
                 client.publish("relais_licht_flur_1_5/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_5 -> AUS");
                 pcf8574_4.digitalWrite(P5, !LOW);
                 client.publish("relais_licht_flur_1_5/OUT","off");
                delay(100);
              }
      }
      
/////////////////////////////////////////////////////////////////////////// Bank 4 - Relais 6
    if (strcmp(topic,"relais_licht_flur_1_6/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_6 -> AN");
                 pcf8574_4.digitalWrite(P6, !HIGH);
                 client.publish("relais_licht_flur_1_6/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_6 -> AUS");
                 pcf8574_4.digitalWrite(P6, !LOW);
                 client.publish("relais_licht_flur_1_6/OUT","off");
                delay(100);
              }
      }
      
/////////////////////////////////////////////////////////////////////////// Bank 4 - Relais 7
    if (strcmp(topic,"relais_licht_flur_1_7/IN")==0) {

        // ON und OFF Funktion auslesen
        if ((char)payload[0] == 'o' && (char)payload[1] == 'n') {  
                 Serial.println("relais_7 -> AN");
                 pcf8574_4.digitalWrite(P7, !HIGH);
                 client.publish("relais_licht_flur_1_7/OUT","on");
                delay(100);
              }

        if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') {  
                 Serial.println("relais_7 -> AUS");
                 pcf8574_4.digitalWrite(P7, !LOW);
                 client.publish("relais_licht_flur_1_7/OUT","off");
                delay(100);
              }
      }
      

      

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
      client.publish("relais_licht_wohnzimmer_1_0/IN","off");  
      client.subscribe("relais_licht_wohnzimmer_1_1/IN");
      client.publish("relais_licht_wohnzimmer_1_1/IN","off"); 
      client.subscribe("relais_licht_wohnzimmer_1_2/IN");
      client.publish("relais_licht_wohnzimmer_1_2/IN","off"); 
      client.subscribe("relais_licht_wohnzimmer_1_3/IN");
      client.publish("relais_licht_wohnzimmer_1_3/IN","off"); 
      client.subscribe("relais_licht_wohnzimmer_1_4/IN");
      client.publish("relais_licht_wohnzimmer_1_4/IN","off"); 
      client.subscribe("relais_licht_wohnzimmer_1_5/IN");
      client.publish("relais_licht_wohnzimmer_1_5/IN","off"); 
      client.subscribe("relais_licht_wohnzimmer_1_6/IN");
      client.publish("relais_licht_wohnzimmer_1_6/IN","off"); 
      client.subscribe("relais_licht_wohnzimmer_1_7/IN");
      client.publish("relais_licht_wohnzimmer_1_7/IN","off"); 

      client.subscribe("relais_licht_wohnzimmer_2_0/IN");
      client.publish("relais_licht_wohnzimmer_2_0/IN","off");  
      client.subscribe("relais_licht_wohnzimmer_2_1/IN");
      client.publish("relais_licht_wohnzimmer_2_1/IN","off"); 
      client.subscribe("relais_licht_wohnzimmer_2_2/IN");
      client.publish("relais_licht_wohnzimmer_2_2/IN","off"); 
      client.subscribe("relais_licht_wohnzimmer_2_3/IN");
      client.publish("relais_licht_wohnzimmer_2_3/IN","off"); 
      client.subscribe("relais_licht_wohnzimmer_2_4/IN");
      client.publish("relais_licht_wohnzimmer_2_4/IN","off"); 
      client.subscribe("relais_licht_wohnzimmer_2_5/IN");
      client.publish("relais_licht_wohnzimmer_2_5/IN","off"); 
      client.subscribe("relais_licht_wohnzimmer_2_6/IN");
      client.publish("relais_licht_wohnzimmer_2_6/IN","off"); 
      client.subscribe("relais_licht_wohnzimmer_2_7/IN");
      client.publish("relais_licht_wohnzimmer_2_7/IN","off");       
                                         
      client.subscribe("relais_licht_wohnzimmer_3_0/IN");
      client.publish("relais_licht_wohnzimmer_3_0/IN","off");  
      client.subscribe("relais_licht_wohnzimmer_3_1/IN");
      client.publish("relais_licht_wohnzimmer_3_1/IN","off"); 
      client.subscribe("relais_licht_wohnzimmer_3_2/IN");
      client.publish("relais_licht_wohnzimmer_3_2/IN","off"); 
      client.subscribe("relais_licht_wohnzimmer_3_3/IN");
      client.publish("relais_licht_wohnzimmer_3_3/IN","off"); 
      client.subscribe("relais_licht_wohnzimmer_3_4/IN");
      client.publish("relais_licht_wohnzimmer_3_4/IN","off");  
      client.subscribe("relais_licht_wohnzimmer_3_5/IN");
      client.publish("relais_licht_wohnzimmer_3_5/IN","off"); 
      client.subscribe("relais_licht_wohnzimmer_3_6/IN");
      client.publish("relais_licht_wohnzimmer_3_6/IN","off"); 
      client.subscribe("relais_licht_wohnzimmer_3_7/IN");
      client.publish("relais_licht_wohnzimmer_3_7/IN","off");      

/////////////////////////////////////////////////////////////////////// BANK 4 Flur

      client.subscribe("relais_licht_flur_1_0/IN");
      client.publish("relais_licht_flur_1_0/IN","off");  
      client.subscribe("relais_licht_flur_1_1/IN");
      client.publish("relais_licht_flur_1_1/IN","off"); 
      client.subscribe("relais_licht_flur_1_2/IN");
      client.publish("relais_licht_flur_1_2/IN","off"); 
      client.subscribe("relais_licht_flur_1_3/IN");
      client.publish("relais_licht_flur_1_3/IN","off"); 
      client.subscribe("relais_licht_flur_1_4/IN");
      client.publish("relais_licht_flur_1_4/IN","off"); 
      client.subscribe("relais_licht_flur_1_5/IN");
      client.publish("relais_licht_flur_1_5/IN","off"); 
      client.subscribe("relais_licht_flur_1_6/IN");
      client.publish("relais_licht_flur_1_6/IN","off"); 
      client.subscribe("relais_licht_flur_1_7/IN");
      client.publish("relais_licht_flur_1_7/IN","off"); 

    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}


void setup() {

 //OTA Setup für Firmware
  ArduinoOTA.setHostname("24KanalRelaisWohnzimmer");
  ArduinoOTA.setPassword("7n6WkRpZtxtkykyMUx329");
  ArduinoOTA.begin();


// MQTT Broker
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

// Serielle Kommunikation starten
  Serial.begin(115200);

  // Verbindung zum WiFI aufbauen

  Serial.print("Verbindung zu SSID -> ");
  Serial.println(ssid);

  // WiFi 
  IPAddress ip(192, 168, 5, 10);
	IPAddress dns(192, 168, 1, 1);  
	IPAddress subnet(255, 255, 0, 0);
	IPAddress gateway(192, 168, 1, 1);

	WiFi.config(ip, dns, gateway, subnet);
  
  WiFi.begin(ssid, password);

  // Wifi AP deaktivieren
  WiFi.mode(WIFI_STA);

  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Erfolgreich mit dem WiFi verbunden!");
  Serial.print("IP 24 Relaiskarte : ");
  Serial.println(WiFi.localIP());
  Serial.print("ID : ");
  Serial.println(kartenID);

// pcf8574 Expander konfigurieren
/////////////////////////////////////////////////////////////////////////// Konfig Relais
  pcf8574_1.pinMode(P0, OUTPUT);
  pcf8574_1.pinMode(P1, OUTPUT);
  pcf8574_1.pinMode(P2, OUTPUT);
  pcf8574_1.pinMode(P3, OUTPUT); 
  pcf8574_1.pinMode(P4, OUTPUT); 
  pcf8574_1.pinMode(P5, OUTPUT); 
  pcf8574_1.pinMode(P6, OUTPUT); 
  pcf8574_1.pinMode(P7, OUTPUT);     
  pcf8574_1.begin();
/////////////////////////////////////////////////////////////////////////// 

/////////////////////////////////////////////////////////////////////////// Relais OFF
pcf8574_1.digitalWrite(P0, !LOW);
pcf8574_1.digitalWrite(P1, !LOW);
pcf8574_1.digitalWrite(P2, !LOW);
pcf8574_1.digitalWrite(P3, !LOW);
pcf8574_1.digitalWrite(P4, !LOW);
pcf8574_1.digitalWrite(P5, !LOW);
pcf8574_1.digitalWrite(P6, !LOW);
pcf8574_1.digitalWrite(P7, !LOW);
///////////////////////////////////////////////////////////////////////////  

/////////////////////////////////////////////////////////////////////////// Konfig Relais
pcf8574_2.pinMode(P0, OUTPUT);
pcf8574_2.pinMode(P1, OUTPUT);
pcf8574_2.pinMode(P2, OUTPUT);
pcf8574_2.pinMode(P3, OUTPUT); 
pcf8574_2.pinMode(P4, OUTPUT); 
pcf8574_2.pinMode(P5, OUTPUT); 
pcf8574_2.pinMode(P6, OUTPUT); 
pcf8574_2.pinMode(P7, OUTPUT);     
pcf8574_2.begin();
/////////////////////////////////////////////////////////////////////////// 

/////////////////////////////////////////////////////////////////////////// Relais OFF
pcf8574_2.digitalWrite(P0, !LOW);
pcf8574_2.digitalWrite(P1, !LOW);
pcf8574_2.digitalWrite(P2, !LOW);
pcf8574_2.digitalWrite(P3, !LOW);
pcf8574_2.digitalWrite(P4, !LOW);
pcf8574_2.digitalWrite(P5, !LOW);
pcf8574_2.digitalWrite(P6, !LOW);
pcf8574_2.digitalWrite(P7, !LOW);
///////////////////////////////////////////////////////////////////////////  

/////////////////////////////////////////////////////////////////////////// Konfig Relais
pcf8574_3.pinMode(P0, OUTPUT);
pcf8574_3.pinMode(P1, OUTPUT);
pcf8574_3.pinMode(P2, OUTPUT);
pcf8574_3.pinMode(P3, OUTPUT); 
pcf8574_3.pinMode(P4, OUTPUT); 
pcf8574_3.pinMode(P5, OUTPUT); 
pcf8574_3.pinMode(P6, OUTPUT); 
pcf8574_3.pinMode(P7, OUTPUT);     
pcf8574_3.begin();
/////////////////////////////////////////////////////////////////////////// 

/////////////////////////////////////////////////////////////////////////// Relais OFF
pcf8574_3.digitalWrite(P0, !LOW);
pcf8574_3.digitalWrite(P1, !LOW);
pcf8574_3.digitalWrite(P2, !LOW);
pcf8574_3.digitalWrite(P3, !LOW);
pcf8574_3.digitalWrite(P4, !LOW);
pcf8574_3.digitalWrite(P5, !LOW);
pcf8574_3.digitalWrite(P6, !LOW);
pcf8574_3.digitalWrite(P7, !LOW);
///////////////////////////////////////////////////////////////////////////  

/////////////////////////////////////////////////////////////////////////// Konfig Relais
pcf8574_4.pinMode(P0, OUTPUT);
pcf8574_4.pinMode(P1, OUTPUT);
pcf8574_4.pinMode(P2, OUTPUT);
pcf8574_4.pinMode(P3, OUTPUT); 
pcf8574_4.pinMode(P4, OUTPUT); 
pcf8574_4.pinMode(P5, OUTPUT); 
pcf8574_4.pinMode(P6, OUTPUT); 
pcf8574_4.pinMode(P7, OUTPUT);     
pcf8574_4.begin();
/////////////////////////////////////////////////////////////////////////// 

/////////////////////////////////////////////////////////////////////////// Relais OFF
pcf8574_4.digitalWrite(P0, !LOW);
pcf8574_4.digitalWrite(P1, !LOW);
pcf8574_4.digitalWrite(P2, !LOW);
pcf8574_4.digitalWrite(P3, !LOW);
pcf8574_4.digitalWrite(P4, !LOW);
pcf8574_4.digitalWrite(P5, !LOW);
pcf8574_4.digitalWrite(P6, !LOW);
pcf8574_4.digitalWrite(P7, !LOW);
/////////////////////////////////////////////////////////////////////////// 

}

//****************************************************************************************** VOID LOOP
void loop() {

  // OTA Handle starten
  ArduinoOTA.handle();  

  if (!client.connected()) {
    reconnect();
  }
  client.loop();


  ///////////////////////////////////////////////////////////////////////// Daten schreiben im Intervall Temperatur
  if (millis() - previousMillis_LOOP_schleife_1 > interval_LOOP_schleife_1) {

      previousMillis_LOOP_schleife_1 = millis();   // aktuelle Zeit abspeichern
 

    }



  delay(100);
}