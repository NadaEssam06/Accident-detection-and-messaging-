#include <TinyGPS++.h>         //Library for using GPS functions 
#include <SoftwareSerial.h> 
#include <HardwareSerial.h> 
TinyGPSPlus gps;               //Object gps for class TinyGPSPlus 
#define SERIAL2_RX PA3 // Replace with RX pin for Serial2 (check your board's documentation) 
#define SERIAL2_TX PA2 
HardwareSerial Serial2(PA3, PA2); 
void setup() 
{ 
  Serial1.begin(9600);         //Begins Serial comunication at Serial Port 1 at 9600 baudrate 
  Serial2.begin(9600);        //Begins Serial comunication at Seria2 Port 1 at 9600 baudrate 
  delay(4000); 
  //pinMode(pin, uint32_t dwMode) 
} 
 
 
void loop() 
{ 
 
  GPSDelay(1000); 
  unsigned long start; 
  double lat_val, lng_val; 
  bool loc_valid; 
  lat_val = gps.location.lat();        //Gets the latitude 
  loc_valid = gps.location.isValid();  
  lng_val = gps.location.lng();        //Gets the longitude 
 
  
 
  if (!loc_valid)                     //Excecutes when invalid data is received from GPS 
  { 
 
    //lcd.print("Waiting"); 
 
    Serial.print("Latitude : "); 
 
    Serial.println("*****"); 
 
    Serial.print("Longitude : "); 
 
    Serial.println("*****"); 
 
    delay(4000); 
 
    //lcd.clear(); 
 
  } 
 
  else                              //Excutes when valid data is received from GPS 
  { 
 
    Serial.println("GPS READING: "); 
    Serial.print("Latitude : "); 
    Serial.println(lat_val, 6);   //Prints latitude at Serial Monitor 
    //lcd.setCursor(0,0); 
    Serial.print("Longitude : "); 
    Serial.println(lng_val, 6);   //Prints longitude at Serial monitor 
    delay(4000); 
 
  } 
 
} 
 
 
static void GPSDelay(unsigned long ms)          //Delay for receiving data from GPS 
{ 
 
  unsigned long start = millis(); 
 
  do 
 
  { 
 
    while (Serial2.available())  
 
    gps.encode(Serial2.read()); 
 
  } while (millis() - start < ms); 
 
}
