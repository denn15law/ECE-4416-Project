
char data= 0;
int ledPin = 9; // choose the pin for the LED
int inputPin2 = 3;
int inputPin1 = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0; 
int val2 = 0; // variable for reading the pin status
 
void setup() {
  pinMode(ledPin, OUTPUT); 
//  pinMode(ledPin2, OUTPUT); // declare LED as output
  pinMode(inputPin1, INPUT);     // declare sensor as input
  pinMode(inputPin2, INPUT); 
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}
void code(){
  while (Serial.available()>0){
    data = Serial.read();      //Read the incoming data and store it into variable data
    Serial.println(data);        //Print Value inside data in Serial monitor
    
    if(data == '1')            //Checks whether value of data is equal to 1 
      digitalWrite(ledPin, HIGH);  //If value is 1 then LED turns ON
    else if(data == '0')       //Checks whether value of data is equal to 0
      digitalWrite(ledPin, LOW);   //If value is 0 then LED turns OFF
  } 
}

void loop(){
   if(Serial.available() > 0)  // Send data only when you receive data:
  {
    code();
  } 

  val = digitalRead(inputPin1);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
  
}
