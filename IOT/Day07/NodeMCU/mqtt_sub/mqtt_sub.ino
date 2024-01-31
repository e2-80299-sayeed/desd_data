#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ArduinoMqttClient.h>

const char *ssid = "SUNBEAM";
const char *password = "1010101010";

const char *server = "172.18.4.83";
unsigned int port = 1883;

WiFiClient wific;
MqttClient mqttc(wific);

void setup() {
  // put your setup code here, to run once:
  pinMode(D0, OUTPUT);

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

  if(!mqttc.connect(server, port)){
    while(1);
  }
  Serial.println("Connection successful");
  mqttc.subscribe("room/fan");
}

void loop() {
  // put your main code here, to run repeatedly:
  int size = mqttc.parseMessage();
  if(size){
    char str[size];
    for(int i = 0 ; i < size ; i++)
      str[i] = (char)mqttc.read();
    
    if(strcmp(str, "ON") == 0){
      digitalWrite(D0, HIGH);
      Serial.println("Recieved : ON");
    }else if(strcmp(str, "OFF") == 0){
      digitalWrite(D0, LOW);
      Serial.println("Recieved : OFF");
    }
  }

}





