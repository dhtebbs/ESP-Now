#include <esp_now.h>
#include <WiFi.h>

// Structure example to receive data
// Must match the sender structure
typedef struct struct_message {
    char message[25];
    unsigned int counter;
} struct_message;

// Create a struct_message called myData
struct_message myData;

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  digitalWrite (ledPin, HIGH);  // turn on the LED
  delay(500); // wait for half a second or 500 milliseconds
  digitalWrite (ledPin, LOW); // turn off the LED
  delay(500); // wait for half a second or 500 milliseconds
}
 
void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  pinMode (ledPin, OUTPUT);
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_register_recv_cb(OnDataRecv);
  
}
 
void loop() {

}
