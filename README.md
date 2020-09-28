# Home-Automation-Using-Nodemcu-and-Thingspeak
Here we use Nodemcu-12e and Thingspeak to create an application of home automation we transmit the pir data which detetcts any motion to our thingspeak server which is then graphed
# Sensor interfacing with arduino
So in this case we are using a pir sensor module which has a digital output and its output pin gies high when it detects a motion. We connect the Dout pin of pir to any digital pin of arduino which we prefer. We connect the 3.3V pin from nodemcu to Vin of pir and GND to GND of pir to provide it power supply.
# Sensitivity settings on pir
Generally a pir has a 2 potentiometers attached to it by which we can change its sensitivity. The pot which is in line with the GND pin is used for sensitivity settings and can provide a maximum sensitivity of 6 meters
# Setting up Thingspeak 
First you need to have a matlab account for thingspeak once you create that you will have something named as channels in navigation bar and go to my channels and then click on new channel and then it will ask a form to fill up and make sure to choose only a specified number of fields of how much data you are monitoring.
# Arduino IDE code and API for thingspeak
In my arduino code as you can see their are 2 api keys required one is the write api key 

