/**
 * WiFi Indoor Positioning using Machine Learning
 *
 * This is a single file sketch for easy deployment, but we recommend you
 * extract the WiFiIndoorPositioning class to its own file.
 */

#include <stdio.h>
#include <string.h>

#include "WiFi.h"
#include "eloquent.h"
#include "eloquent/networking/wifi/WifiScanner.h"

#include <LiquidCrystal_I2C.h>

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);


class WiFiIndoorPositioning {
    public:

        /**
         * Get current room id
         */
        template<typename Scanner>
        int predictRoomId(Scanner& scanner) {
            float x[13] = {0};
            uint16_t votes[3] = { 0 };

            scanner.scan();
            convertToFeatures(scanner, x);

            if (x[10] <= -40.5) {  if (x[2] <= -44.5) {   votes[0] += 1;  } else {  if (x[0] <= -47.5) {  if (x[0] <= -58.5) {   votes[2] += 1;  } else {   votes[1] += 1;  }   } else {  if (x[5] <= -46.0) {   votes[2] += 1;  } else {   votes[0] += 1;  }   }   }   } else {  if (x[5] <= -39.5) {  if (x[7] <= -57.0) {   votes[2] += 1;  } else {   votes[1] += 1;  }   } else {   votes[0] += 1;  }   } 
            if (x[0] <= -46.5) {  if (x[6] <= -90.5) {   votes[2] += 1;  } else {  if (x[6] <= -43.5) {   votes[0] += 1;  } else {  if (x[10] <= -89.5) {   votes[2] += 1;  } else {  if (x[10] <= -40.0) {   votes[1] += 1;  } else {  if (x[7] <= -51.5) {   votes[0] += 1;  } else {   votes[1] += 1;  }   }   }   }   }   } else {   votes[0] += 1;  } 
            if (x[6] <= -43.0) {  if (x[5] <= -42.5) {   votes[2] += 1;  } else {   votes[0] += 1;  }   } else {  if (x[5] <= -44.5) {  if (x[9] <= -43.0) {   votes[2] += 1;  } else {   votes[1] += 1;  }   } else {  if (x[7] <= -65.0) {  if (x[7] <= -68.5) {   votes[0] += 1;  } else {   votes[2] += 1;  }   } else {   votes[0] += 1;  }   }   } 
            if (x[9] <= -89.5) {   votes[2] += 1;  } else {  if (x[5] <= -44.5) {  if (x[4] <= -43.0) {  if (x[4] <= -88.5) {   votes[1] += 1;  } else {   votes[2] += 1;  }   } else {   votes[1] += 1;  }   } else {  if (x[10] <= -91.5) {   votes[2] += 1;  } else {  if (x[9] <= -42.5) {   votes[0] += 1;  } else {  if (x[0] <= -56.5) {   votes[2] += 1;  } else {   votes[0] += 1;  }   }   }   }   } 
            if (x[5] <= -42.5) {  if (x[7] <= -64.5) {   votes[2] += 1;  } else {  if (x[2] <= -42.5) {   votes[1] += 1;  } else {  if (x[7] <= -61.0) {   votes[0] += 1;  } else {   votes[1] += 1;  }   }   }   } else {  if (x[10] <= -91.0) {   votes[2] += 1;  } else {   votes[0] += 1;  }   } 
            if (x[5] <= -42.5) {  if (x[7] <= -63.5) {   votes[2] += 1;  } else {   votes[1] += 1;  }   } else {   votes[0] += 1;  } 
            if (x[5] <= -42.5) {  if (x[10] <= -40.0) {  if (x[0] <= -58.5) {  if (x[0] <= -59.5) {   votes[1] += 1;  } else {   votes[2] += 1;  }   } else {  if (x[10] <= -89.0) {   votes[2] += 1;  } else {   votes[1] += 1;  }   }   } else {  if (x[0] <= -45.5) {  if (x[7] <= -57.0) {   votes[2] += 1;  } else {   votes[1] += 1;  }   } else {   votes[0] += 1;  }   }   } else {  if (x[0] <= -47.5) {  if (x[9] <= -44.5) {   votes[0] += 1;  } else {   votes[2] += 1;  }   } else {   votes[0] += 1;  }   } 
            if (x[10] <= -40.0) {  if (x[2] <= -44.5) {  if (x[10] <= -91.0) {   votes[2] += 1;  } else {   votes[0] += 1;  }   } else {  if (x[7] <= -64.0) {  if (x[5] <= -33.5) {   votes[2] += 1;  } else {   votes[0] += 1;  }   } else {  if (x[10] <= -87.5) {   votes[1] += 1;  } else {  if (x[0] <= -47.5) {   votes[1] += 1;  } else {   votes[0] += 1;  }   }   }   }   } else {  if (x[4] <= -43.5) {   votes[2] += 1;  } else {  if (x[0] <= -49.0) {   votes[1] += 1;  } else {   votes[0] += 1;  }   }   } 
            if (x[0] <= -47.5) {  if (x[3] <= -42.0) {   votes[2] += 1;  } else {  if (x[10] <= -88.5) {  if (x[5] <= -47.5) {   votes[1] += 1;  } else {  if (x[9] <= -46.5) {   votes[0] += 1;  } else {   votes[2] += 1;  }   }   } else {   votes[1] += 1;  }   }   } else {  if (x[4] <= -92.5) {   votes[2] += 1;  } else {   votes[0] += 1;  }   } 
            if (x[7] <= -68.0) {  if (x[0] <= -51.5) {   votes[2] += 1;  } else {  if (x[8] <= -86.5) {   votes[2] += 1;  } else {   votes[0] += 1;  }   }   } else {  if (x[7] <= -54.0) {  if (x[2] <= -89.5) {   votes[2] += 1;  } else {  if (x[0] <= -54.5) {   votes[1] += 1;  } else {  if (x[5] <= -48.0) {   votes[1] += 1;  } else {   votes[0] += 1;  }   }   }   } else {   votes[1] += 1;  }   } 
            

            // return argmax of votes
            uint8_t classIdx = 0;
            float maxVotes = votes[0];

            for (uint8_t i = 1; i < 3; i++) {
                if (votes[i] > maxVotes) {
                    classIdx = i;
                    maxVotes = votes[i];
                }
            }

            return (lastRoomId = classIdx);
        }

        /**
         * Get current room name
         */
        template<typename Scanner>
        String predictRoomName(Scanner& scanner) {
            uint8_t roomId = predictRoomId(scanner);

            switch (roomId) {
                
                case 0: return (lastRoomName = "hallway");
                
                case 1: return (lastRoomName = "kitchen");
                
                case 2: return (lastRoomName = "meeting room");
                
                default: return (lastRoomName = "???");
            }
        }

        /**
         * Test if current location is the given one by id
         */
        bool isIn(uint8_t roomId) {
            return roomId == lastRoomId;
        }

        /**
         * Test if current location is the given one by name
         */
        bool isIn(String roomName) {
            return roomName == lastRoomName;
        }


    protected:
        uint8_t lastRoomId = 255;
        String lastRoomName;

        template<typename Scanner>
        void convertToFeatures(Scanner& scanner, float *x) {
            while (scanner.hasNext()) {
                String ssid = scanner.ssid();
                float rssi = scanner.rssi();

                scanner.next();

                
                if (ssid == "BELL154") {
                    x[0] = rssi;
                    continue;
                }
                
                if (ssid == "ORBI87") {
                    x[1] = rssi;
                    continue;
                }
                
                if (ssid == "BELL205") {
                    x[2] = rssi;
                    continue;
                }
                
                if (ssid == "NETGEAR") {
                    x[3] = rssi;
                    continue;
                }
                
                if (ssid == "Rogers443") {
                    x[4] = rssi;
                    continue;
                }
                
                if (ssid == "HE-2.4G-ground") {
                    x[5] = rssi;
                    continue;
                }
                
                if (ssid == "NETGEAR_EXT") {
                    x[6] = rssi;
                    continue;
                }
                
                if (ssid == "HE-2.4G-upstairs") {
                    x[7] = rssi;
                    continue;
                }
                
                if (ssid == "NETGEAR00") {
                    x[8] = rssi;
                    continue;
                }
                
                if (ssid == "Turbo") {
                    x[9] = rssi;
                    continue;
                }
                
                if (ssid == "SantosIG") {
                    x[10] = rssi;
                    continue;
                }
                
                if (ssid == "NETGEAR00-Guest") {
                    x[11] = rssi;
                    continue;
                }
                
                if (ssid == "VIRGIN186") {
                    x[12] = rssi;
                    continue;
                }
                
            }
        }
};


WiFiIndoorPositioning positioning;


void setup() {
    // initialize LCD
    lcd.init();
    // turn on LCD backlight                      
    lcd.backlight();
    Serial.begin(115200);
    Serial.println("Instructions");
    Serial.println("\tMove around your house/space and read the detected room/zone on the Serial monitor");
}


void loop() {
    lcd.setCursor(0, 0);
    Serial.print("Current location: ");
    Serial.println(positioning.predictRoomName(wifiScanner));

    if (positioning.isIn("hallway")) {
        Serial.println("You are currently in the hallway");
        lcd.print("You are in the");
        lcd.setCursor(0,1);
        lcd.print("hallway");
    }
    else if (positioning.isIn("meeting room")) {
        Serial.println("You are currently in the meeting room");
        lcd.print("You are in the");
        lcd.setCursor(0,1);
        lcd.print("meeting room");
    }
    else if (positioning.isIn("kitchen")) {
        Serial.println("You are currently in the kitchen");
        lcd.print("You are in the");
        lcd.setCursor(0,1);
        lcd.print("kitchen");
    }

    // customize as per your needs

    delay(3000);
    lcd.clear();
}
