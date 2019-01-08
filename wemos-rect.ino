#include <ESP8266WiFi.h>
#include <WiFiClient.h>
// #include <ArduinoJson.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_GFX.h>

#define WEMOS_D0     16
#define WEMOS_D1     5
#define WEMOS_D2     4
#define WEMOS_D3     0
#define WEMOS_D4_LED 2
#define WEMOS_D5     14
#define WEMOS_D6     12
#define WEMOS_D7     13
#define WEMOS_D8     15
#define WEMOS_TX     1
#define WEMOS_RX     3

#define TFT_CS   WEMOS_D2
#define TFT_DC   WEMOS_D3
#define TFT_RST  WEMOS_D1

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  wemosSetup();
  ledSetup();
  wifiSetup();
  tftSetup();
}

void loop() {
  ttfAlphabet255();
  delay(5000);
  ttfAlphabet96();
  delay(5000);
  wifiTftScan();
  delay(10000);
}

