#include "WiFi.h"

void setup() {
  Serial.begin(115200);
  delay(1000);                     // give time for serial

  WiFi.mode(WIFI_MODE_STA);
  delay(100);                      // 🔥 IMPORTANT

  Serial.println("MacAddress is:");
  Serial.println(WiFi.macAddress());
}

void loop() {}