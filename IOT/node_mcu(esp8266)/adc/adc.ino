void setup() {
  // put your setup code here, to run once:
pinMode(A0, INPUT);
Serial.begin(115200);

Serial.flush();
Serial.println("Serial Setup is completed");
}

void loop() {
  // put your main code here, to run repeatedly:
float value = analogRead(A0);
Serial.printf("Sensor value = %f\n", value);
delay(3000);
}
