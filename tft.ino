// LED   - 3.3V
// SCK   - D5
// SDA   - D7
// A0    - D3
// Reset - D1
// CS    - D2
// GND   - GND
// Vcc   - 5V

// Color definitions
// #define ST77XX_BLACK      0x0000
// #define ST77XX_WHITE      0xFFFF
// #define ST77XX_RED        0xF800
// #define ST77XX_GREEN      0x07E0
// #define ST77XX_BLUE       0x001F
// #define ST77XX_CYAN       0x07FF
// #define ST77XX_MAGENTA    0xF81F
// #define ST77XX_YELLOW     0xFFE0
// #define ST77XX_ORANGE     0xFC00

void tftSetup() {
  tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(30, 80);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(1);
  tft.print("Connecting...");
}

void ttfAlphabet() {
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(1);
  char c = 0;
  for (int y = 0; y < 127; y += 8) {
    for (int x = 0; x < 127; x += 8) {
      tft.setCursor(x, y);
      tft.print(c);
      c++;
    }
  }
}

void ttfSetCursor1(int y, int x) {
  tft.setCursor(x * 6, y * 8);
}

