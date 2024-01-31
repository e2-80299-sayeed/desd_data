#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ESP8266HTTPClient.h>

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

  pinMode(A0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A0);
  String body = "{ \"temperature\":" + String(value) + " }";
  // { "temperature":1024}

  HTTPClient httpclient;
  WiFiClient wificlient;
  httpclient.begin(wificlient, "http://172.18.4.83:4000/temperature");
  httpclient.addHeader("content-type", "application/json");
  int statuscode = httpclient.POST(body);
  Serial.printf("Status Code : %d\n", statuscode);

  delay(5000);

}





