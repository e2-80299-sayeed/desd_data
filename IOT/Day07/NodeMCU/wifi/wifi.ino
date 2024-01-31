#include<ESP8266WiFi.h>
#include<WiFiClient.h>

const char *ssid = "SUNBEAM";
const char *password = "1010101010";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.flush();

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi is connected");
  Serial.print("IP Address : ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Inside loop()");
  delay(3000);

}





