// Network SSID
const char* wifiSsid = "Vika";
const char* wifiPassword = "w+79107385802";

void wifiSetup() {
  
}

void wifiTestLoop() {
  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  delay(1000);
  Serial.println();
  Serial.println();
  WiFi.mode(WIFI_STA);
  Serial.println("WiFi disconnect");
  WiFi.disconnect();

  ledBlink(2, 100);

  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0)
    Serial.println("no networks found");
  else
  {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i)
    {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(") ");
      Serial.print(" [");
      Serial.print(WiFi.channel(i));
      Serial.print("] ");
      Serial.println((String) wifiEncryptionTypeStr(WiFi.encryptionType(i)));
      delay(10);
    }
  }
  Serial.println("");

  // Connect WiFi
  delay(1000);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(wifiSsid);
  WiFi.hostname("Wemos");
  WiFi.begin(wifiSsid, wifiPassword);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Print the IP address
  Serial.print("IP address: ");
  Serial.print(WiFi.localIP());
}

void wifiTftScan() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_MAGENTA);
  tft.setTextSize(1);
  tft.setTextWrap(false);
  ttfSetCursor1(0, 0);
  tft.print("WiFi disconnect");

  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  ttfSetCursor1(1, 0);
  tft.print("scan done");
  if (n == 0) {
    ttfSetCursor1(2, 0);
    tft.print("no networks found");
  } else {
    ttfSetCursor1(2, 0);
    tft.print(n);
    tft.print(" networks found");
    for (int i = 0; i < n; ++i)
    {
      ttfSetCursor1(3 + i * 2, 0);
      // Print SSID and RSSI for each network found
      tft.setTextColor(ST77XX_GREEN);
      tft.print(i + 1);
      tft.print(" ");
      tft.setTextColor(ST77XX_WHITE);
      tft.print(WiFi.SSID(i));

      ttfSetCursor1(4 + i * 2, 0);
      tft.print("  ");
      tft.setTextColor(ST77XX_RED);
      tft.print(WiFi.RSSI(i));
      tft.print(" dBm  ");
      tft.setTextColor(ST77XX_YELLOW);
      tft.print(WiFi.channel(i));
      tft.print("  ");
      tft.setTextColor(ST77XX_BLUE);
      tft.print((String) wifiEncryptionTypeStr(WiFi.encryptionType(i)));
      delay(10);
    }
  }
}

String wifiEncryptionTypeStr(uint8_t authmode) {
  switch (authmode) {
    case ENC_TYPE_NONE:
      return "NONE";
    case ENC_TYPE_WEP:
      return "WEP";
    case ENC_TYPE_TKIP:
      return "TKIP";
    case ENC_TYPE_CCMP:
      return "CCMP";
    case ENC_TYPE_AUTO:
      return "AUTO";
    default:
      return "?";;
  }
}

