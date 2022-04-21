#define con 5
#define rec A5 

unsigned long i;

void setup() {
  pinMode(con,OUTPUT);
  pinMode(rec,INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  for( i=0; i<1000; i++){
    if(digitalRead(rec) == HIGH){
      i=0;
      digitalWrite(con,LOW);
      digitalWrite(LED_BUILTIN, HIGH);
    }
  }
  digitalWrite(con,HIGH);
  digitalWrite(LED_BUILTIN, LOW);

}
