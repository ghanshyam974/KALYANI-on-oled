#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDR   0x3C

Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);                  // SDA = GPIO21, SCL = GPIO22

  if (!display.begin(SCREEN_ADDR, true)) {
    Serial.println(F("SH1106 not found"));
    for (;;);
  }

  display.clearDisplay();              // clears old content
  display.setTextColor(SH110X_WHITE);
  display.setTextSize(2);

  display.setCursor(0, 10);
  display.println("Hello");
  display.setCursor(0, 34);
  display.println("GHANSHYAM");

  display.display();                   // send to the screen
}

void loop() {
}