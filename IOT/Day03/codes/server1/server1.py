import temperature.create
import temperature.read
import temperature.delete
import temperature.delete
import temperature.update

temp = float(input("Enter temperature : "))
loc = input("Enter location : ")
temperature.create.insert_temperature(temp, loc)

temps = temperature.read.get_temperatures()
for temp in temps:
    print(temp)

loc = input("\nEnter location to be deleted :")
temperature.delete.delete_temp(loc)

print()

temps = temperature.read.get_temperatures()
for temp in temps:
    print(temp)

temp = float(input("Enter temperature : "))
loc = input("Enter location : ")
temperature.update.update_temps(loc, temp)

print()

temps = temperature.read.get_temperatures()
for temp in temps:
    print(temp)