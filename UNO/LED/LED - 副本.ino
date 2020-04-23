int sensePin = A2;
int ledPin = 9;
int Mode = 0;

void setup() 
{

  pinMode(ledPin,OUTPUT);
  
}

void loop() 
{
  Mode = analogRead(sensePin);

  if(Mode < 100)
  {
    digitalWrite(ledPin, HIGH);
    delay(5000);
    digitalWrite(ledPin, LOW);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }

}
