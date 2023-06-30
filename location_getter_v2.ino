#include "WiFi.h"
#include "eloquent.h"
#include "eloquent/networking/wifi/WifiScanner.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <LiquidCrystal_I2C.h>
#include "C:\Users\user\PycharmProjects\Indoor_Pos_AI\model.h"
int lcdColumns = 16;
int lcdRows = 2;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

String location;
int count;
char** dictionary;
float* RSSIs;

void setup() {
    RandomForest forest;
    
    FILE* ptr;
    FILE *fp = fopen("C:/Users/user/PycharmProjects/Indoor_Pos_AI/networks_legend.txt","r");
    char ch;
    char curr;

    if (fp == NULL) {
        printf("file can't be opened \n");
    }
    while(!feof(fp)) {
        curr = fgetc(fp);
        if (curr == '\n') { // Increment count if this character is newline
            count = count + 1;
        }
    }
    // Close the file
    fclose(fp);

    char dictionary[count][1000];

    
    // Stores the data from networks_legend in a string array
    ptr = fopen("networks_legend.txt", "r");
    if (ptr == NULL) {
        printf("Error opening file.");
    }
    int line = 0;
    while (!feof(ptr) && !ferror(ptr)) {
        if (fgets(dictionary[line], 100, ptr) != NULL) {
            line++;
        }
    }
    fclose(ptr);

    /*
    for (int i = 0; i < line; i++) {
        printf("%f", dictionary[i]);
    }
    */

    
    // Opening file in reading mode
    ptr = fopen("networks_legend.txt", "r");
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
    for (char c = getc(fp); c != EOF; c = getc(fp)) {
        if (c == '\n') { // Increment count if this character is newline
            count = count + 1;
        }
    }
    // Close the file
    fclose(ptr);

    // initialize LCD
    lcd.init();
    // turn on LCD backlight
    lcd.backlight();
    lcd.setCursor(0, 0);

    Serial.begin(115200);
    delay(2000);

      /*
      Serial.println("Instructions:");
      Serial.println("\tEnter the name of the location to start scanning");
      Serial.println("\tEnter 'stop' to stop scanning");
      */

    wifiScanner.identifyByMAC();
    wifiScanner.identifyBySSID();

    float RSSIs[count];
    for (int k = 0; k < count; k++) {
        RSSIs[k] = 0.0;
    }
}

void loop() {
    if (Serial.available()) {
        location = Serial.readStringUntil('\n');
    }
    wifiScanner.scan();
    int numNetworks = WiFi.scanNetworks();

    for (int i = 0; i < numNetworks; i++) {
        for (int j = 0; j < count; j++) {
            if (wifiScanner.idAt(i) == dictionary[j]) {
                RSSIs[j] = wifiScanner.rssiAt(i);
            }
        }
    }

    for(int i = 0; i < count; i++) {
      Serial.print(dictionary[i]);
      Serial.print(": ");
      Serial.print(RSSIs[i], 1);
      Serial.print("\n");
    }

    delay(2000);

  
    /*
    if (location != "" && location != "stop") {
        wifiScanner.scan();
        // wifiScanner.printAsJson(Serial);
        // Serial.println(wifiScanner.id());
        int numNetworks = WiFi.scanNetworks();

        for (uint8_t i = 0; i < numNetworks; i++) {
            if (wifiScanner.idAt(i) == "ESP8266_ONE" || wifiScanner.idAt(i) == "ESP8266_TWO" || wifiScanner.idAt(i) == "ESP8266_THREE" || wifiScanner.idAt(i) == "ESP8266_FOUR") {
                Serial.print(wifiScanner.idAt(i));
                Serial.print('"');
                Serial.print(':');
                Serial.print(wifiScanner.rssiAt(i));
                Serial.println("");
                String message = wifiScanner.idAt(i) + ": " + wifiScanner.rssiAt(i);
                scrollText(1, message, 250, lcdColumns);
            }
        }
    
        delay(2000);
    }
    */
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
