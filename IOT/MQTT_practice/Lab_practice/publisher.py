import paho.mqtt.client as mqtt

mqttc = mqtt.Client("Publisher")

def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("Publisher is connected successfully")
    else :
        print(f"Publisher is not connected Error code : {rc}")

def on_publish(client, userdata, mid) :
    print("message is published successfully")

mqttc.on_connect = on_connect
mqttc.on_publish = on_publish

host = "localhost"
mqttc.connect(host)

topic = "topic/good"
payload = "Hi sourav"
mqttc.publish(topic,payload)

mqttc.disconnect()
