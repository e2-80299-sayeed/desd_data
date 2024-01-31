#  import mqtt module
import paho.mqtt.client as mqtt

# create instance of client class (creating mqtt client)
mqttc = mqtt.Client("Subscriber")

# define all required callbacks 
def on_connect(client, userdata, flags, rc):
    if rc == 0:
        #subscribe for topic 
        print("Publisher is connected successfully")
        topic = "topic/hello"
        mqttc.subscribe(topic)

    else :
        print(f"Publisher is not connected Error code :{rc} ")

def on_message(client, userdata, message):
    print(f"Recieved msg :\"{message.payload}\" on topic \"{message.topic}\"")

#register our callback functions with our clients instance 
mqttc.on_connect = on_connect
mqttc.on_message = on_message

#connect with broker
host = "localhost"
mqttc.connect(host)


#run forever loop to keep subscriber alive
mqttc.loop_forever()
