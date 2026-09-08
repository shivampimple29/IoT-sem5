// ESP32-1 TRANSMITTER
#include <WiFi.h>

const char* ssid = "ESP32_PIR_NET";
const char* password = "12345678";

const int pirPin = 27;

WiFiServer server(3333);

void setup() {
  Serial.begin(115200);
  pinMode(pirPin, INPUT);

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  Serial.println();
  Serial.println("ESP32-1 PIR TRANSMITTER");
  Serial.print("AP IP: ");
  Serial.println(WiFi.softAPIP());

  server.begin();
}

void loop() {

  int motion = digitalRead(pirPin);

  WiFiClient client = server.available();

  if (client) {

    Serial.println("ESP32-2 connected");

    if (motion == HIGH) {
      client.println("MOTION_DETECTED");
      Serial.println("MOTION_DETECTED");
    } 
    else {
      client.println("NO_MOTION");
      Serial.println("NO_MOTION");
    }

    client.stop();
  }

  delay(100);
}
