## mosquitto configuration

1. open mosquitto.conf
    sudo vim /etc/mosquitto/mosquitto.conf
2. Add following lines at the end of file and save it
    listener 1883 0.0.0.0
    allow_anonymous true

- Restart the  Mosquitto broker
    sudo systemctl restart mosquitto