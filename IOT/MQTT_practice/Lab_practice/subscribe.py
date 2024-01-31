import paho.mqtt.client as mqtt

mqttc = mqtt.Client("Subscriber")

def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("subscriber is connected successfully")
        topic = "topic/good"
        mqttc.subscribe(topic)
    else :
        print(f"Publisher is not connected Error code : {rc}")

def on_message(client, userdata, message) :
    print(f"Recieved msg : \"{message.payload}\" on topic \"{message.topic}\"")

mqttc.on_connect = on_connect
mqttc.on_message = on_message

host = "localhost"
mqttc.connect(host)

mqttc.loop_forever()