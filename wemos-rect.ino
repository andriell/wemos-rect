#include <ESP8266WiFi.h>
#include <WiFiClient.h>

void setup() {
  Serial.begin(74880);
  checkSetup();
  ledSetup();
  wifiSetup();
}

void loop() {
  wifiTestLoop();
}

