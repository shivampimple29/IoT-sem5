// ESP32-2 RECEIVER
#include <WiFi.h>

const char* ssid = "ESP32_PIR_NET";
const char* password = "12345678";

const char* serverIP = "192.168.4.1";
const int serverPort = 3333;

const int ledPin = 2;
const int buzzerPin = 27;

WiFiClient client;

void setup() {

  Serial.begin(115200);
  delay(1000);

  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);

  Serial.println();
  Serial.println("ESP32-2 PIR RECEIVER");

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Wi-Fi Connected!");
  Serial.print("Receiver IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {

  if (client.connect(serverIP, serverPort)) {

    unsigned long startTime = millis();

    while (!client.available() && millis() - startTime < 2000) {
      delay(10);
    }

    if (client.available()) {

      String message = client.readStringUntil('\n');
      message.trim();

      Serial.print("Received: ");
      Serial.println(message);

      if (message == "MOTION_DETECTED") {

        Serial.println(">>> MOTION DETECTED <<<");

        digitalWrite(ledPin, HIGH);
        digitalWrite(buzzerPin, HIGH);

      }
      else if (message == "NO_MOTION") {

        Serial.println("NO MOTION");

        digitalWrite(ledPin, LOW);
        digitalWrite(buzzerPin, LOW);
      }
    }

    client.stop();
  }

  delay(500);
}
