#include "arduino_secrets.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "thingProperties.h"

int lcdAddress = 0x27;
int lcdColumns = 16;
int lcdRows = 2;
LiquidCrystal_I2C lcd(lcdAddress, lcdColumns, lcdRows);  

void setup() {
  Serial.begin(9600);
  delay(1500);

  Wire.begin(D1, D2); // Specify SDA and SCL pins

  lcd.begin( lcdColumns, lcdRows);  

  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello, World!");
  delay(1000);

  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
}

void onStrChange()  {
  Serial.print("Received string: ");
  Serial.println(str);
  
  lcd.clear();
  lcd.setCursor(0, 0);

  lcd.print(str);
}
