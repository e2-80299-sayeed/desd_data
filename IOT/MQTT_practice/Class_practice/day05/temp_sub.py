#  import mqtt module
import paho.mqtt.client as mqtt
import utils.database as db
# create instance of client class (creating mqtt client)
mqttc = mqtt.Client("Publisher")

# define all required callbacks 
def on_connect(client, userdata, flags, rc):
    if rc == 0:
        #subscribe for topic 
        print("Publisher is connected successfully")
        topic = "sensor/temperature"
        mqttc.subscribe(topic)

    else :
        print(f"Publisher is not connected Error code :{rc} ")

def on_message(client, userdata, message):
    print(f"Recieved msg :\"{message.payload}\"on topic\"{message.topic}\"")
    temp = float(message.payload)
    print(f"Temperature = {temp}")

 query = f"insert into temperatures(temperature, location) values({temp}, \"indrayani\");"

    db.execute_query(query)#register our callback functions with our clients instance 
mqttc.on_connect = on_connect
mqttc.on_message = on_message

#connect with broker
host = "localhost"
mqttc.connect(host)


#run forever loop to keep subscriber alive
mqttc.loop_forever()
