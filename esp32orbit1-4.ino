#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);
uint8_t levels[4] = {0, 0, 0, 0};
uint8_t frameBuf[4];
uint8_t frameIndex = 0;
bool inFrame = false;

void setup() {
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
}

void loop() {
  while (Serial.available()) {
    uint8_t b = Serial.read();

    if (b == 255) {
      inFrame = true;
      frameIndex = 0;
      continue;
    }

    if (inFrame) {
      frameBuf[frameIndex++] = b;
      if (frameIndex == 4) {
        for (int i = 0; i < 4; i++) levels[i] = frameBuf[i];
        inFrame = false;
      }
    }
  }

  drawMeters();
}

void drawMeters() {
  display.clearDisplay();

  int barWidth = 20;
  int barMaxHeight = 40;
  int barTop = 4;
  int spacing = 32; 
  int startX = 6;

  for (int i = 0; i < 4; i++) {
    int x = startX + i * spacing;
    int barHeight = map(levels[i], 0, 127, 0, barMaxHeight);

    display.drawRect(x, barTop, barWidth, barMaxHeight, SSD1306_WHITE);
    display.fillRect(x, barTop + (barMaxHeight - barHeight), barWidth, barHeight, SSD1306_WHITE);


    display.setTextSize(0.5);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(x - 2, barTop + barMaxHeight + 2);
    display.print("ORB ");
    display.setCursor(x + 7, barTop + barMaxHeight + 11);
    display.print(i + 1);
  }

  display.display();
}