void setup() {
  pinMode(7,OUTPUT);
}
 
void loop() {   
  if(analogRead(A0)>450)
  digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  else if(analogRead(A0)<300)                   // wait for a second
  digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
  delay(10);
}
