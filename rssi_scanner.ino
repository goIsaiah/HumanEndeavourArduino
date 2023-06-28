/**
 * WiFi scanner example
 * Print WiFi hotspots with their RSSI in Json format
 *
 * Enter the name of the location to start scanning
 * Enter 'stop' to stop the scanning
 */

// replace with WiFiNINA.h if you use a different board
#include "WiFi.h"

#include "eloquent.h"
#include "eloquent/networking/wifi/WifiScanner.h"


String location;


void setup() {
    Serial.begin(115200);
    delay(2000);
    Serial.println("Instructions:");
    Serial.println("\tEnter the name of the location to start scanning");
    Serial.println("\tEnter 'stop' to stop scanning");

    // you can identify networks either by MAC address
    wifiScanner.identifyByMAC();
    // or SSID (default)
    wifiScanner.identifyBySSID();
}

void loop() {
    // await user to input his current location or "stop" to abort scanning
    if (Serial.available()) {
        location = Serial.readStringUntil('\n');
    }

    // if a location is set, perform scan
    if (location != "" && location != "stop") {
        String message;
        message+=(location);
        message+=(": {");
        wifiScanner.scan();
        int numNetworks = WiFi.scanNetworks();

        for (uint8_t i = 0; i < numNetworks; i++) {
            if (wifiScanner.idAt(i) == "ESP8266_ONE" || wifiScanner.idAt(i) == "ESP8266_TWO" || wifiScanner.idAt(i) == "ESP8266_THREE" || wifiScanner.idAt(i) == "ESP8266_FOUR") {
                message += ("\"" + wifiScanner.idAt(i));
                message+=('"');
                message+=(':');
                message+=(wifiScanner.rssiAt(i));
                message+=(',');
            }
        }
        
        message.remove(message.length()-1, 1);
        message+=("}");
        Serial.println(message);
    }
}
