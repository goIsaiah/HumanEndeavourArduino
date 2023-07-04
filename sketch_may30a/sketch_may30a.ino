#include <eloquent.h>

//#include "eDataStructures.h"

#define MAX_NETWORKS 10

using namespace Eloquent::DataStructures;

double features[MAX_NETWORKS];
Array knownNetworks("");

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();

    knownNetworks.push("SSID #0");
    knownNetworks.push("SSID #1");
    knownNetworks.push("SSID #2");
    knownNetworks.push("SSID #3");
    // and so on
}
