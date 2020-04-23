void setup() {
  Serial.begin(9600);

}

void loop() {
  Serial.write("Hello,This is a test massage!");
  delay(1000);
}
