import temperature.create
import temperature.read

temp = float(input("Enter Temperature : "))
loc = input("Enter location : ")
temperature.create.insert_temp( temp,loc)

temps = temperature.read.get_temp()

for temp in temps :
    print(temp)