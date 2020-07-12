int count =0;// just counting seconds
int buzzer = 11;// pin to connect to buzzer or relay
void setup() {
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);// set pin 11 as output

}

void loop() {
  int v = analogRead(A0);// read the output pin of the module
   // HIGH is when motion is detected. 
  if (v == LOW){
    digitalWrite(buzzer,LOW);// set buzzer pin LOW
   count =0; 
  }else{
    count++;
    digitalWrite(buzzer,HIGH);// Set buzzer pin HIGH
    Serial.print(count);
    Serial.println("-Detected");    
  }
 delay(1000);// wait for 1 second
} 
