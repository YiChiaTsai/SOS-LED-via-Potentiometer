/*
  DigitalReadSerial
 Reads a digital input on pin 2, prints the result to the serial monitor

 This example code is in the public domain.
 */

// digital pin 2 has a pushbutton attached to it. Give it a name:
int ledPin = 9;
int pushButton = 2;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(ledPin, OUTPUT);
  pinMode(pushButton, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  Serial.println(buttonState);
  delay(1);        // delay in between reads for stability

  if(buttonState){
    Serial.println("Let's get started SOS rescue!");
    proceedSOS();
    Serial.println("Complete SOS rescue!");
    delay(1000);
  }
}

void detectPotentiometer(){
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);
  float fadeValue = sensorValue * (256.0 / 1023.0);
  Serial.println(voltage + fadeValue);
  
  analogWrite(ledPin, fadeValue);
}

void proceedSOS(){
  //The following demonstrate the SOS signal by blink program.
  //Note that - = **
  //S -> * * *
  detectPotentiometer();
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
  detectPotentiometer();
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
  detectPotentiometer();
  delay(500);
  digitalWrite(ledPin, LOW);
  
  //The space between two letters is equal to three dots.
  delay(1500);

  //O -> - - -
  detectPotentiometer();
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(500);
  detectPotentiometer();
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(500);
  detectPotentiometer();
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(500);

  //The space between two letters is equal to three dots.
  delay(1500);
  
  //S -> * * *
  detectPotentiometer();
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
  detectPotentiometer();
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
  detectPotentiometer();
  delay(500);
  digitalWrite(ledPin, LOW);

  //The space between two words is equal to Seven dots.
  delay(3500);
}



