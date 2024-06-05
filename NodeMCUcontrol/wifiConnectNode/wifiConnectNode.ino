// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPL4PwGzgaLj"
#define BLYNK_TEMPLATE_NAME "Eps32Control"
#define BLYNK_AUTH_TOKEN "hNRthDN3zVKx6JC7X-5rz51RypNlr9HV"
#define LED_PIN 23

#include <BlynkSimpleWifi.h>
#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include <WiFiGeneric.h>
#include <WiFiMulti.h>
#include <WiFiSTA.h>
#include <WiFiScan.h>
#include <WiFiServer.h>
#include <WiFiType.h>
#include <WiFiUdp.h>



const char *ssid = "CYBERSPACE 2.4GHZ";  //since it is a charachter of many chars (and not a string) we need a pointer
const char *pass = "40174066";

BLYNK_WRITE(V23){
  // Local variable `value` stores the incoming LED switch state (1 or 0)
  // Based on this value, the physical LED on the board will be on or off:
  int value = param.asInt();

  if (value == 1) {
    digitalWrite(LED_PIN, HIGH);
    Serial.print("value =");
    Serial.println(value);
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.print("value = ");
    Serial.println(value);
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN , OUTPUT);
  Serial.begin(9600);
  delay(10);
  Serial.print("Connecting to ..... ");
  Serial.println(ssid);

  WiFi.begin(ssid,pass);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.println(".");
  }
  Serial.println("WiFi connected");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  delay(10);
}
