#include <Servo.h>

const int lm35pin = A0;

Servo myServo;

void setup()
{
  Serial.begin(9600);
  myServo.attach(9);
}

void loop()
{
  // Read the analog value from LM35
  int sensorValue = analogRead(lm35pin);

  // Convert ADC value to voltage
  float voltage = sensorValue * (5.0 / 1023.0);

  // Convert voltage to temperature (LM35 gives 10mV per °C)
  float tempc = voltage * 100.0;

  // Print results to the Serial Monitor
  Serial.println("Temperature:");
  Serial.println(tempc);
  Serial.println("degree C");

  delay(1000);

  if (tempc > 25)
  {
    myServo.write(180);
    delay(1000);

    myServo.write(0);
    delay(1000);
  }
  else
  {
    myServo.write(0);
  }
}