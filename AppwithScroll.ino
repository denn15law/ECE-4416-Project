int data = 0;
int ledPin = 9;
int inputPin1 = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0; 
int val2 = 0; // variable for reading the pin status


void setup() {
Serial.begin(9600);
pinMode(ledPin,OUTPUT);
pinMode(inputPin1, INPUT);     // declare sensor as input
}

void app() {
  if(Serial.available()>0){
  data = Serial.read();
  Serial.println(data);
  analogWrite(ledPin, data);
  }
}

void loop() {
app(); 
}






