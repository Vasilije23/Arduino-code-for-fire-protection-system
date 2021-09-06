import serial
import time

arduino = serial.Serial('COM8', 9600)
time.sleep(2)

i = 1

while i:
    print arduino.readline()
    print("Enter 3 to turn all on. Enter 2 to turn flame detector on. Enter 1 to turn smoke detector on.")
    x = int(input("You Entered : "))

    if x < 0:
        i = 0
    
    if(x == 3):
        arduin0.write(3)
        print("all turned on")
        time.sleep(1)

    elif(x == 2):
        arduin0.write(2);
        print("flame detector turned on")
        time.sleep(1)

    elif(x == 1):
        arduino.write(1)
        print("smoke detector turned on")
        time.sleep(1)

    else:
        arduino.write(0)
        print("all turned off")

print("kraj")
