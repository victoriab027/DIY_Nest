import RPi.GPIO as GPIO
import time

# Define the GPIO pin number connected to your solenoid
solenoid_pin = 4

# Set up the GPIO mode and pin
GPIO.setmode(GPIO.BCM)
GPIO.setup(solenoid_pin, GPIO.OUT)

try:
    while True:
        # Activate the solenoid (push motion)
        GPIO.output(solenoid_pin, GPIO.HIGH)
        
        # Wait for a short duration (e.g., 0.1 seconds)
        time.sleep(0.1)
        
        # Deactivate the solenoid (release motion)
        GPIO.output(solenoid_pin, GPIO.LOW)
        
        # Wait for 1 second
        time.sleep(1)

except KeyboardInterrupt:
    # If you manually stop the script with Ctrl+C, clean up the GPIO settings
    GPIO.cleanup()
