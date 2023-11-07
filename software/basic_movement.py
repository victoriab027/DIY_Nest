import RPi.GPIO as GPIO
import time

# Set the GPIO mode to BCM
GPIO.setmode(GPIO.BCM)

# Set the GPIO pin to an output
solenoid_pin = 3
GPIO.setup(solenoid_pin, GPIO.OUT)

try:
    while True:
        # Apply voltage to the solenoid
        GPIO.output(solenoid_pin, GPIO.HIGH)

        # Wait for 1 second
        time.sleep(1)

        # Turn off the voltage to the solenoid
        GPIO.output(solenoid_pin, GPIO.LOW)

        # Wait for 1 second
        time.sleep(1)

except KeyboardInterrupt:
    # If you press Ctrl+C, clean up and exit
    GPIO.cleanup()
