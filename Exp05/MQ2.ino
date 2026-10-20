const int gasSensor=34;
const int ledPin=23;
const int buzzer=22;
int sensorValue;

int threshold = 1800;

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(buzzer, OUTPUT);

    Serial.begin(115200);
}

void loop()
{
    sensorValue = analogRead(gasSensor);

    Serial.print("Gas Sensor Value: ");
    Serial.println(sensorValue);

    if(sensorValue > threshold)
    {
        digitalWrite(ledPin, HIGH);
        digitalWrite(buzzer, HIGH);

        Serial.println("Gas/Smoke Detected!");
    }
    else
    {
        digitalWrite(ledPin, LOW);
        digitalWrite(buzzer, LOW);

        Serial.println("Air Quality Normal");
    }

    delay(1000);
}
