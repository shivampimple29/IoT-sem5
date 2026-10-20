// Q3 - Alternate Blinking of Two LEDs

const int led1 = 13;
const int led2 = 12;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  // LED1 ON for 500 ms
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  delay(500);

  // LED2 ON for 1000 ms
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(1000);
}

