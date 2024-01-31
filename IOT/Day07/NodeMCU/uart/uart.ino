void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  Serial.flush();
  Serial.println("Serial Setup is completed");

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Inside loop()");
  delay(3000);
}
