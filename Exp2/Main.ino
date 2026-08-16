// 1A

void setup(){
    pinMode(LED, OUTPUT);
}

void loop(){
    digitalWrite(LED, HIGH);
}


// 1B

const int LED = 13;

void setup(){
    pinMode(LED, OUTPUT);
}

void loop(){
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    delay(1000);
}


// 1C

// i) Slow

const int LED = 13;

void setup(){
    pinMode(LED, OUTPUT);
}

void loop(){
    digitalWrite(LED, HIGH);
    delay(1000);    // slow
    digitalWrite(LED, LOW);
    delay(1000);
}


// ii) Medium

const int LED = 13;

void setup(){
    pinMode(LED, OUTPUT);
}

void loop(){
    digitalWrite(LED, HIGH);
    delay(500);     // medium
    digitalWrite(LED, LOW);
    delay(500);
}


// iii) Fast

void loop(){
    digitalWrite(LED, HIGH);
    delay(200);     // fast
    digitalWrite(LED, LOW);
    delay(200);
}


// 1D

const int LED = 13;
const int BUTTON = 10;

void setup(){
    pinMode(LED, OUTPUT);
    pinMode(BUTTON, INPUT);
}

void loop(){
    if (digitalRead(BUTTON) == HIGH){
        digitalWrite(LED, HIGH);
    }
    else{
        digitalWrite(LED, LOW);
    }
}


// 1E

const int LED = 13;

void setup(){
    pinMode(LED, OUTPUT);
}

void loop(){
    digitalWrite(LED, HIGH);
}


// 1F

const int LED = 13;
const int LDR = 10;

void setup(){
    pinMode(LED, OUTPUT);
    pinMode(LDR, INPUT);
}

void loop(){
    if (digitalRead(LDR) == HIGH){
        digitalWrite(LED, HIGH);
    }
    else{
        digitalWrite(LED, LOW);
    }
}