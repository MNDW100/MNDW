#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

byte roll0[8] = {0b00100,0b01110,0b11111,0b10101,0b11111,0b01110,0b01010,0b10101};
byte roll1[8] = {0b00000,0b00100,0b01110,0b11111,0b10101,0b01110,0b00100,0b01010};
byte roll2[8] = {0b10101,0b01010,0b01110,0b11111,0b10101,0b11111,0b01110,0b00100};
byte roll3[8] = {0b01000,0b01110,0b10111,0b11101,0b11111,0b01110,0b00101,0b00010};
byte surprised[8] = {0b00100,0b01110,0b10101,0b11111,0b01110,0b01110,0b00100,0b01110};
byte crack[8] = {0b10000,0b01000,0b00100,0b00010,0b00100,0b01000,0b10000,0b00000};

const unsigned long FRAME_MS = 150;
unsigned long lastFrame = 0;
byte rollPhase = 0;
byte crackCount = 0;
bool complete = false;

void drawPig() {
  lcd.setCursor(0, 0);
  lcd.write(byte(complete ? 4 : rollPhase));
}

void drawStatus() {
  lcd.setCursor(1, 0);
  if (complete) lcd.print("OMG! DONE!     ");
  else lcd.print("ROLLING...     ");
}

void drawFloor() {
  lcd.setCursor(0, 1);
  for (byte i = 0; i < 16; i++) {
    if (i < crackCount) lcd.write(byte(5));
    else lcd.print('-');
  }
}

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, roll0);
  lcd.createChar(1, roll1);
  lcd.createChar(2, roll2);
  lcd.createChar(3, roll3);
  lcd.createChar(4, surprised);
  lcd.createChar(5, crack);
  drawPig();
  drawStatus();
  drawFloor();
}

void loop() {
  if (complete) return;

  unsigned long now = millis();
  if (now - lastFrame >= FRAME_MS) {
    lastFrame = now;
    rollPhase++;
    if (rollPhase >= 4) {
      rollPhase = 0;
      crackCount++;
      drawFloor();
      if (crackCount >= 16) {
        complete = true;
        drawStatus();
      }
    }
    drawPig();
  }
}
