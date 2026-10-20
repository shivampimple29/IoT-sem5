#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

#include <Servo.h>

Servo myServo;

void setup()
{
  Serial.begin(9600);
  dht.begin();
  myServo.attach(9);
}

void loop()
{
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print results to the Serial Monitor
  Serial.println("Humidity");
  Serial.println(h);
  Serial.println("% |");

  Serial.println("Temperature:");
  Serial.println(t);
  Serial.println("degree C");

  if (h > 70)
  {
    myServo.write(0);
    delay(1000);

    myServo.write(180);
    delay(1000);
  }
  else
  {
    myServo.write(0);
  }
}