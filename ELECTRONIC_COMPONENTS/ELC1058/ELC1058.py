import sys
sys.path.append('/home/pi/Adafruit-Raspberry-Pi-Python-Code/Adafruit_CharLCD')
from Adafruit_CharLCD import Adafruit_CharLCD
lcd=Adafruit_CharLCD()     # instantiate LCD Display
lcd.clear()
from time import sleep
import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)     # set up BCM GPIO numbering
# Set up input pin
GPIO.setup(21, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
# Set up LED output
GPIO.setup(20, GPIO.OUT)
# Callback function to run when motion detected
def motionSensor(channel):
   lcd.clear()
   GPIO.output(20, GPIO.LOW)
   if GPIO.input(21):     # True = Rising
       global counter
       counter += 1
       lcd.message('Motion Detected\n{0}'.format(counter))
       GPIO.output(20, GPIO.HIGH)
# add event listener on pin 21
GPIO.add_event_detect(21, GPIO.BOTH, callback=motionSensor, bouncetime=300) 
counter = 0
try:
   while True:
       sleep(1)         # wait 1 second
finally:                   # run on exit
   GPIO.cleanup()         # clean up
   print "All cleaned up." 