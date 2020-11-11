// Code copied in most part from the factory test code: https://github.com/m5stack/M5Stack/blob/master/examples/Basics/FactoryTest/FactoryTest.ino
//
//


#include <M5Stack.h>
#include "utility/MPU9250.h"
#include "WiFi.h"

char ssid[30];
char outstr[30];

void wifi_test() {
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    delay(100);
    
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.println("WIFI Signal Strength");
    M5.Lcd.println("--------------------");        
    if (n == 0) {
        M5.Lcd.println("no networks found");
    } else {
        for (int i = 0; i < n; ++i) {
            WiFi.SSID(i).toCharArray(ssid, 28);
            sprintf(outstr,"%-20.20s %3d",ssid, WiFi.RSSI(i));
            M5.Lcd.println(outstr);
        }
    }
}

// the setup routine runs once when M5Stack starts up
void setup() {
    
    M5.begin();
    M5.Power.begin();
    Wire.begin();

    // Lcd display
    M5.Lcd.setBrightness(100);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setTextSize(2);

    M5.Lcd.setCursor(0, 0);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.println("WIFI Signal Strength");
    M5.Lcd.println("--------------------");
 }

// the loop routine runs over and over again forever
void loop(){
    wifi_test();
    delay(500);
    M5.update();
}
