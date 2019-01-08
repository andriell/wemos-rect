// Network SSID
const char* wifiSsid = "Vika";
const char* wifiPassword = "password";

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

