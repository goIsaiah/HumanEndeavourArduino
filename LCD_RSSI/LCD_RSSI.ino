#include "WiFi.h"
#include "eloquent.h"
#include "eloquent/networking/wifi/WifiScanner.h"
#include <stdio.h>
#include <string.h>
#include <LiquidCrystal_I2C.h>

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

String location;

void setup() {
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
  lcd.setCursor(0, 0);
  
  Serial.begin(115200);
  delay(2000);

  Serial.println("Instructions:");
  Serial.println("\tEnter the name of the location to start scanning");
  Serial.println("\tEnter 'stop' to stop scanning");

  wifiScanner.identifyByMAC();
  wifiScanner.identifyBySSID();
}

void loop() {
  if (Serial.available()) {
    location = Serial.readStringUntil('\n');
  }

  if (location != "" && location != "stop") {
    wifiScanner.scan();
    // wifiScanner.printAsJson(Serial);
    // Serial.println(wifiScanner.id());
    int numNetworks = WiFi.scanNetworks();

    for (uint8_t i = 0; i < numNetworks; i++) {
      if (wifiScanner.idAt(i) == "ESP8266_ONE" || wifiScanner.idAt(i) == "ESP8266_TWO" || wifiScanner.idAt(i) == "ESP8266_THR" || wifiScanner.idAt(i) == "ESP8266_FOUR") {
        Serial.print(wifiScanner.idAt(i));
        Serial.print('"');
        Serial.print(':');
        Serial.print(wifiScanner.rssiAt(i));
        Serial.println("");
        String message = wifiScanner.idAt(i) + ": " + wifiScanner.rssiAt(i);
        scrollText(1, message, 250, lcdColumns);
      }
      /*
      Serial.print('"');
      Serial.print(wifiScanner.idAt(i));
      Serial.print('"');
      Serial.print(':');
      Serial.print(wifiScanner.rssiAt(i));
      if (i < numNetworks - 1) {
        Serial.print(',');
      }
      Serial.println("");
      */
    }
    
    delay(2000);
  }
  // wifiScanner.scan();
  // wifiScanner.printAsJson(Serial);

}

void scrollText(int row, String message, int delayTime, int lcdColumns) {
  for (int i=0; i < lcdColumns; i++) {
    message = " " + message; 
  } 
  message = message + " "; 
  for (int pos = 0; pos < message.length(); pos++) {
    lcd.setCursor(0, row);
    lcd.print(message.substring(pos, pos + lcdColumns));
    delay(delayTime);
  }
}
