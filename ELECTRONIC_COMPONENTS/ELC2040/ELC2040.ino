const int buttonPin[] = {9,10,11,12};     // the number of the pushbutton pins
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);  
  // initialize the Serial Monitor @ 9600
  Serial.begin(9600);  
  // initialize the keypad pin(s) as an input:
  for(int x=0; x<2; x++)
  {
    pinMode(buttonPin[x], INPUT_PULLUP); 
  }  
}

void loop(){
  // read the state of the keypad value:
  for(int x=0; x<2; x++)
  {
    //signifying the state of which the button is in by reading the appropriate pin #
    buttonState = digitalRead(buttonPin[x]);

    // check if the pushbutton on the keypad is pressed.
    // if it is, the buttonState is LOW:
    if (buttonState == LOW && buttonPin[x] == 9) {    
      // turn LED off:   
      Serial.print("OFF * ");
      // digitalWrite(ledPin, LOW); 
    }
    if (buttonState == LOW && buttonPin[x] == 10) {
      // turn LED off:
      Serial.print("ON *");
      //digitalWrite(ledPin, LOW);
    }
  }
}
