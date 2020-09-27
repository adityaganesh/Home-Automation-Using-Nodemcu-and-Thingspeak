









#include <ESP8266WiFi.h>  
#include <WiFiClient.h>  
#include <ThingSpeak.h>  
const char* ssid = "your ssid";  
const char* password = "your wifi password";  
WiFiClient client;  
unsigned long myChannelNumber =   your channel number;  
const char * myWriteAPIKey = "your write api key";  
//the time we give the sensor to calibrate (10-60 secs according to the datasheet)
int calibrationTime = 30;       
 
//the time when the sensor outputs a low impulse
long unsigned int lowIn;        
 
//the amount of milliseconds the sensor has to be low
//before we assume all motion has stopped
long unsigned int pause = 5000; 
 
boolean lockLow = true;
boolean takeLowTime; 
 
int pirPin = D1;    //the digital pin connected to the PIR sensor's output

 
 
/////////////////////////////
//SETUP
void setup(){
  Serial.begin(115200);
    delay(10);  
  // Connect to WiFi network  
  Serial.println();  
  Serial.println();  
  Serial.print("Connecting to ");  
  Serial.println(ssid);  
  WiFi.begin(ssid, password);  
  while (WiFi.status() != WL_CONNECTED)  
  {  
   delay(500);  
   Serial.print(".");  
  }  
  Serial.println("");  
  Serial.println("WiFi connected");  
  // Print the IP address  
  Serial.println(WiFi.localIP());  
  ThingSpeak.begin(client);  
  pinMode(pirPin, INPUT);
  digitalWrite(pirPin, LOW);
 
  //give the sensor some time to calibrate
  Serial.print("calibrating sensor ");
    for(int i = 0; i < calibrationTime; i++){
      Serial.print(".");
      delay(1000);
      }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
    delay(50);
  }
 
////////////////////////////
//LOOP
void loop(){
    
     if(digitalRead(pirPin) == HIGH){  
     
         ThingSpeak.writeField(myChannelNumber, 1, digitalRead(pirPin), myWriteAPIKey); 
         delay(3000);   
     }


       
       
  }
