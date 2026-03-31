#include <esp_now.h>
#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Change THIS for each ESP (put the OTHER ESP MAC here)
uint8_t peerAddress[] = {0x34, 0x94, 0x54, 0x30, 0xD9, 0xB4};

// Data structure (MUST be identical on both)
typedef struct struct_message {
  char message[32];
} struct_message;

struct_message myData;

// Peer info
esp_now_peer_info_t peerInfo;

// ✅ NEW SEND CALLBACK (UPDATED)
void OnDataSent(const wifi_tx_info_t *info, esp_now_send_status_t status) {
  Serial.print("Send Status: ");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Success" : "Fail");
}

// ✅ NEW RECEIVE CALLBACK (UPDATED)
void OnDataRecv(const esp_now_recv_info_t *info, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));

  Serial.println("=== RECEIVED ===");
  Serial.print("Text: ");
  Serial.println(myData.message);

  delay(200);
  digitalWrite(2, HIGH);
  delay(200);
  digitalWrite(2, LOW);

  Serial.println();
}
Adafruit_SSD1306 display(128,64,&Wire,-1);
 
void setup() {
//Button
pinMode(4,INPUT_PULLUP);


  //OLED SSD1306 setup
 
  Wire.begin(21,22);
  display.begin(SSD1306_SWITCHCAPVCC,0x3C);
  display.clearDisplay(); 
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,10);
 


//ESP NOW setup 
  Serial.begin(115200);
  pinMode(2, OUTPUT);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW Init Failed");
    return;
  }

  // Register BOTH callbacks
  esp_now_register_send_cb(OnDataSent);
  esp_now_register_recv_cb(OnDataRecv);

  // Add peer
  memcpy(peerInfo.peer_addr, peerAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
}

void loop() {
 if(digitalRead(4)==LOW){

  display.println(myData.message);
  display.display();
  }

  strcpy(myData.message, "no");

  // Send data
  esp_now_send(peerAddress, (uint8_t *) &myData, sizeof(myData));

  Serial.println("=== SENT ===");


  delay(2000);
} 