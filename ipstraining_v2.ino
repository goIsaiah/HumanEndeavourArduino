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


class WiFiIndoorPositioning {
    public:

        /**
         * Get current room id
         */
        template<typename Scanner>
        int predictRoomId(Scanner& scanner) {
            float x[4] = {0};
            uint16_t votes[6] = { 0 };

            scanner.scan();
            convertToFeatures(scanner, x);

            if (x[0] <= -66.0) {  if (x[1] <= -63.0) {  if (x[2] <= -72.5) {  if (x[0] <= -82.0) {   votes[2] += 1;  } else {  if (x[3] <= -66.0) {  if (x[2] <= -78.0) {   votes[5] += 1;  } else {   votes[1] += 1;  }   } else {  if (x[2] <= -82.5) {  if (x[2] <= -84.0) {   votes[4] += 1;  } else {  if (x[1] <= -89.5) {   votes[4] += 1;  } else {   votes[1] += 1;  }   }   } else {   votes[4] += 1;  }   }   }   } else {  if (x[0] <= -88.5) {   votes[0] += 1;  } else {  if (x[1] <= -81.5) {   votes[1] += 1;  } else {  if (x[0] <= -75.0) {   votes[2] += 1;  } else {  if (x[0] <= -73.5) {   votes[1] += 1;  } else {  if (x[1] <= -79.5) {   votes[1] += 1;  } else {   votes[2] += 1;  }   }   }   }   }   }   } else {  if (x[0] <= -85.0) {  if (x[3] <= -93.5) {   votes[0] += 1;  } else {  if (x[0] <= -93.5) {  if (x[2] <= -60.5) {   votes[3] += 1;  } else {  if (x[1] <= -49.5) {  if (x[3] <= -82.0) {  if (x[0] <= -94.5) {   votes[3] += 1;  } else {   votes[0] += 1;  }   } else {   votes[0] += 1;  }   } else {   votes[3] += 1;  }   }   } else {  if (x[2] <= -55.0) {   votes[3] += 1;  } else {  if (x[1] <= -52.5) {  if (x[3] <= -88.5) {   votes[3] += 1;  } else {   votes[0] += 1;  }   } else {   votes[3] += 1;  }   }   }   }   } else {   votes[0] += 1;  }   }   } else {  if (x[3] <= -63.5) {  if (x[3] <= -81.5) {   votes[0] += 1;  } else {  if (x[2] <= -67.5) {  if (x[2] <= -85.0) {  if (x[0] <= -52.5) {  if (x[2] <= -87.5) {   votes[5] += 1;  } else {   votes[1] += 1;  }   } else {   votes[5] += 1;  }   } else {   votes[5] += 1;  }   } else {  if (x[3] <= -71.0) {   votes[5] += 1;  } else {   votes[1] += 1;  }   }   }   } else {  if (x[0] <= -55.5) {  if (x[3] <= -54.5) {   votes[1] += 1;  } else {   votes[4] += 1;  }   } else {  if (x[1] <= -83.5) {   votes[5] += 1;  } else {   votes[1] += 1;  }   }   }   } 
            if (x[1] <= -79.5) {  if (x[0] <= -66.5) {  if (x[3] <= -62.5) {   votes[1] += 1;  } else {  if (x[0] <= -80.0) {   votes[2] += 1;  } else {  if (x[2] <= -82.5) {  if (x[3] <= -50.5) {   votes[1] += 1;  } else {   votes[4] += 1;  }   } else {   votes[4] += 1;  }   }   }   } else {  if (x[1] <= -83.0) {  if (x[2] <= -89.5) {   votes[1] += 1;  } else {  if (x[1] <= -87.5) {  if (x[2] <= -72.5) {  if (x[3] <= -54.5) {  if (x[1] <= -91.0) {  if (x[2] <= -82.0) {   votes[1] += 1;  } else {   votes[5] += 1;  }   } else {   votes[5] += 1;  }   } else {   votes[4] += 1;  }   } else {  if (x[1] <= -89.0) {   votes[5] += 1;  } else {   votes[1] += 1;  }   }   } else {   votes[5] += 1;  }   }   } else {  if (x[3] <= -76.0) {   votes[5] += 1;  } else {  if (x[2] <= -65.0) {   votes[1] += 1;  } else {  if (x[0] <= -59.0) {   votes[1] += 1;  } else {   votes[5] += 1;  }   }   }   }   }   } else {  if (x[0] <= -85.5) {  if (x[3] <= -74.5) {  if (x[1] <= -63.5) {   votes[0] += 1;  } else {  if (x[3] <= -94.5) {   votes[0] += 1;  } else {  if (x[2] <= -52.5) {  if (x[0] <= -93.5) {  if (x[0] <= -94.5) {   votes[3] += 1;  } else {   votes[0] += 1;  }   } else {   votes[3] += 1;  }   } else {  if (x[0] <= -89.5) {   votes[3] += 1;  } else {  if (x[3] <= -81.0) {   votes[0] += 1;  } else {   votes[3] += 1;  }   }   }   }   }   } else {   votes[2] += 1;  }   } else {  if (x[0] <= -70.5) {  if (x[1] <= -70.5) {  if (x[3] <= -66.5) {   votes[2] += 1;  } else {  if (x[1] <= -77.5) {   votes[1] += 1;  } else {  if (x[3] <= -65.5) {   votes[1] += 1;  } else {   votes[2] += 1;  }   }   }   } else {  if (x[0] <= -79.5) {   votes[0] += 1;  } else {   votes[1] += 1;  }   }   } else {  if (x[0] <= -27.5) {  if (x[3] <= -64.0) {  if (x[0] <= -57.0) {  if (x[0] <= -61.5) {   votes[5] += 1;  } else {   votes[1] += 1;  }   } else {   votes[5] += 1;  }   } else {  if (x[1] <= -77.0) {   votes[4] += 1;  } else {  if (x[3] <= -62.0) {   votes[4] += 1;  } else {   votes[1] += 1;  }   }   }   } else {  if (x[1] <= -54.0) {   votes[0] += 1;  } else {  if (x[3] <= -88.5) {   votes[3] += 1;  } else {   votes[0] += 1;  }   }   }   }   }   } 
            if (x[3] <= -63.5) {  if (x[1] <= -80.0) {  if (x[0] <= -71.0) {   votes[1] += 1;  } else {  if (x[1] <= -83.5) {  if (x[1] <= -91.5) {  if (x[0] <= -63.0) {   votes[1] += 1;  } else {  if (x[2] <= -85.0) {   votes[1] += 1;  } else {   votes[5] += 1;  }   }   } else {   votes[5] += 1;  }   } else {  if (x[3] <= -76.0) {   votes[5] += 1;  } else {   votes[1] += 1;  }   }   }   } else {  if (x[0] <= -85.5) {  if (x[3] <= -84.5) {  if (x[3] <= -90.0) {   votes[3] += 1;  } else {  if (x[0] <= -94.5) {   votes[3] += 1;  } else {   votes[0] += 1;  }   }   } else {  if (x[1] <= -62.0) {   votes[0] += 1;  } else {  if (x[3] <= -79.5) {   votes[3] += 1;  } else {  if (x[0] <= -91.5) {   votes[0] += 1;  } else {   votes[3] += 1;  }   }   }   }   } else {  if (x[1] <= -61.5) {   votes[2] += 1;  } else {  if (x[2] <= -71.5) {  if (x[2] <= -85.0) {  if (x[2] <= -87.5) {   votes[5] += 1;  } else {   votes[1] += 1;  }   } else {   votes[5] += 1;  }   } else {   votes[0] += 1;  }   }   }   }   } else {  if (x[2] <= -71.0) {  if (x[0] <= -66.5) {  if (x[0] <= -69.5) {   votes[4] += 1;  } else {  if (x[1] <= -87.0) {   votes[4] += 1;  } else {  if (x[3] <= -60.5) {   votes[5] += 1;  } else {  if (x[0] <= -68.0) {  if (x[1] <= -84.5) {   votes[1] += 1;  } else {   votes[4] += 1;  }   } else {   votes[4] += 1;  }   }   }   }   } else {  if (x[3] <= -59.0) {  if (x[3] <= -62.5) {  if (x[1] <= -83.0) {   votes[5] += 1;  } else {   votes[1] += 1;  }   } else {   votes[1] += 1;  }   } else {  if (x[3] <= -53.5) {   votes[5] += 1;  } else {   votes[4] += 1;  }   }   }   } else {  if (x[0] <= -76.0) {   votes[2] += 1;  } else {   votes[1] += 1;  }   }   } 
            if (x[2] <= -60.5) {  if (x[1] <= -81.5) {  if (x[3] <= -57.5) {  if (x[0] <= -69.0) {  if (x[2] <= -72.0) {   votes[4] += 1;  } else {   votes[1] += 1;  }   } else {  if (x[3] <= -63.5) {  if (x[1] <= -91.0) {  if (x[2] <= -83.0) {   votes[1] += 1;  } else {   votes[5] += 1;  }   } else {   votes[5] += 1;  }   } else {  if (x[2] <= -86.0) {   votes[1] += 1;  } else {  if (x[0] <= -54.5) {  if (x[3] <= -60.0) {  if (x[2] <= -81.0) {  if (x[1] <= -93.0) {   votes[4] += 1;  } else {   votes[1] += 1;  }   } else {  if (x[1] <= -84.5) {   votes[1] += 1;  } else {   votes[5] += 1;  }   }   } else {   votes[5] += 1;  }   } else {   votes[5] += 1;  }   }   }   }   } else {  if (x[0] <= -70.0) {   votes[4] += 1;  } else {  if (x[0] <= -64.0) {  if (x[3] <= -56.0) {   votes[4] += 1;  } else {  if (x[1] <= -84.5) {   votes[1] += 1;  } else {   votes[4] += 1;  }   }   } else {   votes[4] += 1;  }   }   }   } else {  if (x[0] <= -78.5) {  if (x[1] <= -69.5) {   votes[2] += 1;  } else {  if (x[3] <= -86.5) {   votes[3] += 1;  } else {  if (x[0] <= -90.0) {   votes[0] += 1;  } else {   votes[2] += 1;  }   }   }   } else {  if (x[2] <= -70.0) {  if (x[3] <= -62.5) {  if (x[0] <= -61.5) {   votes[5] += 1;  } else {  if (x[0] <= -57.0) {   votes[1] += 1;  } else {   votes[5] += 1;  }   }   } else {   votes[4] += 1;  }   } else {  if (x[1] <= -60.5) {  if (x[1] <= -70.5) {  if (x[3] <= -70.5) {   votes[2] += 1;  } else {  if (x[3] <= -62.5) {  if (x[0] <= -73.0) {   votes[1] += 1;  } else {  if (x[2] <= -65.5) {   votes[2] += 1;  } else {   votes[1] += 1;  }   }   } else {   votes[2] += 1;  }   }   } else {   votes[1] += 1;  }   } else {   votes[3] += 1;  }   }   }   }   } else {  if (x[2] <= -55.5) {  if (x[3] <= -77.5) {   votes[3] += 1;  } else {   votes[2] += 1;  }   } else {  if (x[1] <= -52.5) {  if (x[2] <= -53.0) {   votes[0] += 1;  } else {  if (x[3] <= -90.5) {   votes[3] += 1;  } else {   votes[0] += 1;  }   }   } else {  if (x[2] <= -50.0) {  if (x[1] <= -51.0) {   votes[3] += 1;  } else {  if (x[0] <= -91.0) {  if (x[2] <= -52.5) {   votes[3] += 1;  } else {   votes[0] += 1;  }   } else {   votes[0] += 1;  }   }   } else {   votes[3] += 1;  }   }   }   } 
            if (x[0] <= -87.5) {  if (x[2] <= -55.0) {   votes[3] += 1;  } else {  if (x[1] <= -58.0) {   votes[0] += 1;  } else {  if (x[3] <= -84.5) {  if (x[1] <= -53.0) {   votes[3] += 1;  } else {  if (x[1] <= -46.0) {   votes[0] += 1;  } else {   votes[3] += 1;  }   }   } else {   votes[3] += 1;  }   }   }   } else {  if (x[3] <= -58.5) {  if (x[1] <= -84.5) {  if (x[3] <= -63.0) {  if (x[2] <= -68.5) {   votes[5] += 1;  } else {   votes[1] += 1;  }   } else {  if (x[0] <= -64.0) {   votes[4] += 1;  } else {  if (x[2] <= -79.5) {   votes[1] += 1;  } else {  if (x[3] <= -60.5) {  if (x[2] <= -73.5) {   votes[5] += 1;  } else {   votes[1] += 1;  }   } else {   votes[5] += 1;  }   }   }   }   } else {  if (x[1] <= -77.5) {  if (x[2] <= -63.5) {  if (x[3] <= -62.5) {  if (x[2] <= -65.0) {   votes[1] += 1;  } else {   votes[5] += 1;  }   } else {   votes[2] += 1;  }   } else {   votes[1] += 1;  }   } else {  if (x[1] <= -60.5) {  if (x[0] <= -70.5) {   votes[2] += 1;  } else {  if (x[1] <= -73.5) {   votes[1] += 1;  } else {   votes[4] += 1;  }   }   } else {  if (x[1] <= -24.5) {  if (x[2] <= -62.5) {   votes[3] += 1;  } else {  if (x[1] <= -52.5) {   votes[0] += 1;  } else {  if (x[3] <= -84.5) {   votes[0] += 1;  } else {   votes[3] += 1;  }   }   }   } else {   votes[5] += 1;  }   }   }   }   } else {  if (x[2] <= -82.5) {  if (x[0] <= -68.0) {   votes[1] += 1;  } else {   votes[4] += 1;  }   } else {   votes[4] += 1;  }   }   } 
            if (x[1] <= -81.5) {  if (x[3] <= -61.5) {  if (x[0] <= -69.0) {  if (x[1] <= -87.5) {   votes[4] += 1;  } else {   votes[1] += 1;  }   } else {  if (x[3] <= -64.0) {  if (x[1] <= -92.5) {  if (x[1] <= -93.5) {   votes[5] += 1;  } else {  if (x[0] <= -59.5) {   votes[1] += 1;  } else {   votes[5] += 1;  }   }   } else {   votes[5] += 1;  }   } else {  if (x[2] <= -81.5) {   votes[1] += 1;  } else {  if (x[0] <= -57.5) {  if (x[1] <= -86.0) {   votes[1] += 1;  } else {  if (x[1] <= -83.5) {   votes[5] += 1;  } else {   votes[1] += 1;  }   }   } else {   votes[5] += 1;  }   }   }   }   } else {  if (x[2] <= -68.5) {  if (x[1] <= -95.0) {   votes[1] += 1;  } else {  if (x[1] <= -85.5) {   votes[4] += 1;  } else {  if (x[2] <= -80.5) {   votes[1] += 1;  } else {   votes[4] += 1;  }   }   }   } else {   votes[1] += 1;  }   }   } else {  if (x[0] <= -87.0) {  if (x[1] <= -66.0) {   votes[0] += 1;  } else {  if (x[0] <= -92.5) {  if (x[2] <= -56.0) {  if (x[1] <= -49.5) {   votes[3] += 1;  } else {   votes[0] += 1;  }   } else {  if (x[2] <= -53.5) {   votes[0] += 1;  } else {  if (x[2] <= -52.5) {   votes[3] += 1;  } else {   votes[0] += 1;  }   }   }   } else {  if (x[2] <= -51.5) {   votes[3] += 1;  } else {  if (x[0] <= -88.5) {   votes[0] += 1;  } else {   votes[3] += 1;  }   }   }   }   } else {  if (x[3] <= -83.5) {  if (x[1] <= -52.5) {   votes[0] += 1;  } else {  if (x[1] <= -50.5) {   votes[3] += 1;  } else {   votes[0] += 1;  }   }   } else {  if (x[1] <= -76.5) {  if (x[3] <= -63.0) {  if (x[1] <= -79.5) {   votes[1] += 1;  } else {  if (x[3] <= -66.5) {   votes[2] += 1;  } else {   votes[1] += 1;  }   }   } else {  if (x[3] <= -61.0) {   votes[2] += 1;  } else {   votes[4] += 1;  }   }   } else {  if (x[0] <= -76.0) {   votes[2] += 1;  } else {  if (x[3] <= -66.5) {  if (x[2] <= -71.5) {   votes[5] += 1;  } else {   votes[2] += 1;  }   } else {  if (x[0] <= -74.0) {   votes[1] += 1;  } else {   votes[4] += 1;  }   }   }   }   }   }   } 
            if (x[2] <= -68.5) {  if (x[3] <= -61.5) {  if (x[1] <= -77.5) {  if (x[0] <= -66.5) {  if (x[2] <= -78.0) {   votes[5] += 1;  } else {   votes[1] += 1;  }   } else {  if (x[2] <= -83.5) {   votes[1] += 1;  } else {  if (x[0] <= -60.0) {  if (x[3] <= -62.5) {   votes[5] += 1;  } else {   votes[1] += 1;  }   } else {   votes[5] += 1;  }   }   }   } else {  if (x[2] <= -75.0) {  if (x[2] <= -83.0) {   votes[1] += 1;  } else {   votes[4] += 1;  }   } else {   votes[0] += 1;  }   }   } else {  if (x[2] <= -71.5) {  if (x[0] <= -60.5) {  if (x[2] <= -82.5) {  if (x[2] <= -83.5) {   votes[4] += 1;  } else {   votes[1] += 1;  }   } else {   votes[4] += 1;  }   } else {  if (x[3] <= -53.0) {   votes[5] += 1;  } else {   votes[4] += 1;  }   }   } else {   votes[1] += 1;  }   }   } else {  if (x[3] <= -76.5) {  if (x[0] <= -89.5) {  if (x[2] <= -55.5) {   votes[3] += 1;  } else {  if (x[1] <= -46.0) {   votes[0] += 1;  } else {   votes[3] += 1;  }   }   } else {  if (x[2] <= -58.0) {  if (x[0] <= -41.5) {   votes[2] += 1;  } else {   votes[3] += 1;  }   } else {  if (x[1] <= -46.0) {   votes[0] += 1;  } else {   votes[3] += 1;  }   }   }   } else {  if (x[1] <= -76.5) {  if (x[1] <= -80.5) {   votes[1] += 1;  } else {  if (x[3] <= -66.5) {   votes[2] += 1;  } else {   votes[1] += 1;  }   }   } else {   votes[2] += 1;  }   }   } 
            if (x[1] <= -81.5) {  if (x[2] <= -87.5) {   votes[1] += 1;  } else {  if (x[3] <= -57.5) {  if (x[3] <= -63.5) {  if (x[1] <= -87.5) {  if (x[0] <= -65.5) {  if (x[2] <= -78.0) {   votes[5] += 1;  } else {   votes[1] += 1;  }   } else {   votes[5] += 1;  }   } else {  if (x[0] <= -70.0) {   votes[1] += 1;  } else {   votes[5] += 1;  }   }   } else {  if (x[3] <= -62.5) {   votes[1] += 1;  } else {  if (x[1] <= -87.5) {  if (x[0] <= -65.0) {   votes[4] += 1;  } else {  if (x[3] <= -60.5) {   votes[1] += 1;  } else {   votes[5] += 1;  }   }   } else {  if (x[1] <= -83.0) {   votes[5] += 1;  } else {   votes[4] += 1;  }   }   }   }   } else {  if (x[2] <= -68.5) {   votes[4] += 1;  } else {   votes[1] += 1;  }   }   }   } else {  if (x[0] <= -85.5) {  if (x[1] <= -63.5) {   votes[0] += 1;  } else {  if (x[2] <= -55.0) {  if (x[1] <= -49.5) {   votes[3] += 1;  } else {   votes[0] += 1;  }   } else {  if (x[1] <= -58.0) {   votes[0] += 1;  } else {  if (x[2] <= -52.5) {   votes[3] += 1;  } else {  if (x[3] <= -88.5) {   votes[3] += 1;  } else {  if (x[0] <= -88.5) {  if (x[2] <= -50.0) {   votes[0] += 1;  } else {   votes[3] += 1;  }   } else {   votes[3] += 1;  }   }   }   }   }   }   } else {  if (x[0] <= -70.0) {  if (x[1] <= -60.5) {  if (x[1] <= -77.5) {  if (x[0] <= -73.0) {   votes[1] += 1;  } else {   votes[2] += 1;  }   } else {   votes[2] += 1;  }   } else {   votes[0] += 1;  }   } else {  if (x[0] <= -58.5) {  if (x[1] <= -39.0) {  if (x[2] <= -70.0) {   votes[4] += 1;  } else {   votes[1] += 1;  }   } else {   votes[1] += 1;  }   } else {  if (x[2] <= -71.5) {   votes[5] += 1;  } else {  if (x[3] <= -84.5) {   votes[0] += 1;  } else {   votes[3] += 1;  }   }   }   }   }   } 
            if (x[0] <= -77.5) {  if (x[0] <= -85.5) {  if (x[3] <= -84.5) {  if (x[3] <= -90.5) {   votes[3] += 1;  } else {  if (x[2] <= -56.0) {  if (x[2] <= -59.5) {   votes[0] += 1;  } else {   votes[3] += 1;  }   } else {  if (x[0] <= -94.5) {   votes[3] += 1;  } else {   votes[0] += 1;  }   }   }   } else {  if (x[3] <= -74.5) {  if (x[2] <= -50.0) {   votes[3] += 1;  } else {  if (x[1] <= -60.0) {   votes[0] += 1;  } else {   votes[3] += 1;  }   }   } else {   votes[2] += 1;  }   }   } else {  if (x[2] <= -81.5) {   votes[4] += 1;  } else {  if (x[1] <= -82.5) {   votes[1] += 1;  } else {   votes[2] += 1;  }   }   }   } else {  if (x[3] <= -63.5) {  if (x[0] <= -70.5) {  if (x[3] <= -71.0) {   votes[2] += 1;  } else {   votes[1] += 1;  }   } else {  if (x[2] <= -67.5) {   votes[5] += 1;  } else {  if (x[0] <= -29.5) {   votes[1] += 1;  } else {  if (x[3] <= -88.5) {   votes[3] += 1;  } else {  if (x[3] <= -83.5) {   votes[0] += 1;  } else {   votes[3] += 1;  }   }   }   }   }   } else {  if (x[3] <= -60.5) {  if (x[0] <= -68.0) {  if (x[3] <= -62.0) {   votes[4] += 1;  } else {  if (x[1] <= -83.0) {   votes[4] += 1;  } else {   votes[1] += 1;  }   }   } else {  if (x[1] <= -83.5) {  if (x[1] <= -87.5) {   votes[1] += 1;  } else {   votes[5] += 1;  }   } else {   votes[1] += 1;  }   }   } else {  if (x[2] <= -73.5) {  if (x[2] <= -82.5) {  if (x[2] <= -83.5) {   votes[4] += 1;  } else {   votes[1] += 1;  }   } else {   votes[4] += 1;  }   } else {  if (x[3] <= -56.5) {   votes[5] += 1;  } else {  if (x[1] <= -89.5) {   votes[1] += 1;  } else {   votes[4] += 1;  }   }   }   }   }   } 
            if (x[0] <= -66.5) {  if (x[2] <= -71.5) {  if (x[3] <= -64.0) {  if (x[2] <= -82.5) {   votes[1] += 1;  } else {  if (x[2] <= -79.0) {   votes[2] += 1;  } else {  if (x[3] <= -68.0) {   votes[1] += 1;  } else {   votes[2] += 1;  }   }   }   } else {  if (x[2] <= -82.5) {  if (x[3] <= -53.0) {   votes[4] += 1;  } else {   votes[1] += 1;  }   } else {  if (x[0] <= -68.0) {   votes[4] += 1;  } else {  if (x[1] <= -86.5) {   votes[4] += 1;  } else {  if (x[1] <= -84.5) {   votes[1] += 1;  } else {   votes[5] += 1;  }   }   }   }   }   } else {  if (x[0] <= -83.5) {  if (x[2] <= -52.5) {  if (x[3] <= -86.5) {   votes[3] += 1;  } else {  if (x[1] <= -57.5) {  if (x[1] <= -72.5) {   votes[1] += 1;  } else {   votes[3] += 1;  }   } else {  if (x[2] <= -54.5) {  if (x[1] <= -48.0) {  if (x[2] <= -56.0) {  if (x[0] <= -95.0) {   votes[3] += 1;  } else {   votes[0] += 1;  }   } else {   votes[0] += 1;  }   } else {   votes[3] += 1;  }   } else {   votes[3] += 1;  }   }   }   } else {   votes[0] += 1;  }   } else {  if (x[1] <= -81.5) {   votes[1] += 1;  } else {  if (x[1] <= -75.5) {  if (x[1] <= -76.5) {  if (x[0] <= -73.5) {  if (x[2] <= -69.5) {   votes[2] += 1;  } else {   votes[1] += 1;  }   } else {   votes[2] += 1;  }   } else {   votes[1] += 1;  }   } else {  if (x[0] <= -75.5) {   votes[2] += 1;  } else {   votes[1] += 1;  }   }   }   }   }   } else {  if (x[1] <= -81.5) {  if (x[2] <= -86.0) {   votes[1] += 1;  } else {  if (x[3] <= -53.5) {  if (x[3] <= -62.5) {   votes[5] += 1;  } else {  if (x[0] <= -60.5) {   votes[1] += 1;  } else {  if (x[3] <= -60.0) {   votes[1] += 1;  } else {   votes[5] += 1;  }   }   }   } else {   votes[4] += 1;  }   }   } else {  if (x[2] <= -50.5) {  if (x[0] <= -29.5) {   votes[1] += 1;  } else {   votes[3] += 1;  }   } else {   votes[0] += 1;  }   }   } 
            

            // return argmax of votes
            uint8_t classIdx = 0;
            float maxVotes = votes[0];

            for (uint8_t i = 1; i < 6; i++) {
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
                
                case 0: return (lastRoomName = "female washroom");
                
                case 1: return (lastRoomName = "hallway");
                
                case 2: return (lastRoomName = "kitchen");
                
                case 3: return (lastRoomName = "male washroom");
                
                case 4: return (lastRoomName = "meeting room");
                
                case 5: return (lastRoomName = "noor's room");
                
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

                
                if (ssid == "ESP8266_ONE") {
                    x[0] = rssi;
                    continue;
                }
                
                if (ssid == "ESP8266_FOUR") {
                    x[1] = rssi;
                    continue;
                }
                
                if (ssid == "ESP8266_THREE") {
                    x[2] = rssi;
                    continue;
                }
                
                if (ssid == "ESP8266_TWO") {
                    x[3] = rssi;
                    continue;
                }
                
            }
        }
};


WiFiIndoorPositioning positioning;


void setup() {
    Serial.begin(115200);
    Serial.println("Instructions");
    Serial.println("\tMove around your house/space and read the detected room/zone on the Serial monitor");
}


void loop() {
    Serial.print("Current location: ");
    Serial.println(positioning.predictRoomName(wifiScanner));

    if (positioning.isIn("female washroom")) {
        Serial.println("You are in the female washroom");
    }
    else if (positioning.isIn("male washroom")) {
        Serial.println("You are in the male washroom");
    }
    else if (positioning.isIn("kitchen")) {
        Serial.println("You are in the kitchen");
    }
    else if (positioning.isIn("hallway")) {
        Serial.println("You are in the hallway");
    }
    else if (positioning.isIn("meeting room")) {
        Serial.println("You are in the meeting room");
    }
    else { // noor's room
        Serial.println("You are in Noor's room");
    }

    // customize as per your needs

    delay(5000);
}
