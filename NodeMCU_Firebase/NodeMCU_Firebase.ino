

#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
 
#define FIREBASE_HOST "chexapp-94305.firebaseio.com"
#define FIREBASE_AUTH "L3vx1VdWjjeNN4l5RcOz4B2In9jGlbeOrTK69SnP"
#define WIFI_SSID "Sam iPhone X"
#define WIFI_PASSWORD "banaan123"
 
String myString;
int vr = A0; // variable resistor connected 
int sdata = 0; // The variable resistor value will be stored in sdata.
 
void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(vr ,INPUT);
  // connect to wifi.
  pinMode(D0,OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED)
      {
    Serial.print(".");
    delay(500);
      }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
 
   Firebase.setString("Variable/Value","f ahad");
}
 
void loop()
{
 
sdata = analogRead(vr);
myString = String(sdata); 
Serial.println(myString); 
Firebase.setString("Variable/Value",myString);
delay(1000);            
}
