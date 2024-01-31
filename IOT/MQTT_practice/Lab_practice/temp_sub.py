import paho.mqtt.client as mqtt
import utils.database as db 

mqttc = mqtt.Client("Subscriber")

def on_connect(client, userdata, flags, rc):
    if rc == 0 :
        print("Subscriber is connected successfully")
        topic = "sensor/temperature"
        mqttc.subscribe(topic)
    
    else:
        print(f"Publisher is not connected Error code : {rc}")
        

def on_message(client, userdata, message) :
    print(f"Recieved msg : \"{message.payload}\" on topic \"{message.topic}\"")
    temp = float(message.payload)
    print(f"Temperature = {temp}") 

    query = f"insert into temperature(temperature, location) values({temp}, \"Jammu\");"

    db.execute_query(query)


mqttc.on_connect = on_connect
mqttc.on_message = on_message

host = "localhost"
mqttc.connect(host)

mqttc.loop_forever()