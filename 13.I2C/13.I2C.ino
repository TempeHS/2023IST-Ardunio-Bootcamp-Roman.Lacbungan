/*
  Author: Roman Lacbungan
  Learning Intention:
  The students will learn to use the I2C communication protocol to send and receive
  data with 2IC sensors and actuators

  Success Criteria:
    1.  I understand that I2C is a communication protocol
    2.  I understand that each I2C needs it's own I2C Channel
    3.  I understand that communicating to I2C modules is similar to the serial monitor
    4.  I understand I need to include the `wire-h` library
    5.  I understand that I need to look at the documentation and example code for each I2C module
    6.  I can sucessfully send data to the I2C OLED display
    7.  I can successfully receive data from either Temperature & Humidity Sensor, Air pressure Sensor or Acceleration Sensor in the sensor kit.

  Student Notes:
    
  Documentation: 
    https://www.arduino.cc/reference/en/language/functions/communication/wire/


  Examples:
    OLED: https://github.com/TempeHS/TempeHS_Ardunio_Boilerplate/blob/main/TempeHS_Sensor_Catalogue/Sensor%20Kit/0.96_OLED_Display/0.96_OLED_Display.ino
    3 Axis: Acceleromter: https://github.com/TempeHS/TempeHS_Ardunio_Boilerplate/blob/main/TempeHS_Sensor_Catalogue/Sensor%20Kit/3_Axis_Accel_Sensor/3_Axis_Accel_Sensor.ino
    Temperature & Humidity: https://github.com/TempeHS/TempeHS_Ardunio_Boilerplate/blob/main/TempeHS_Sensor_Catalogue/Sensor%20Kit/Temp_and_Humid_Sensor/Temp_and_Humid_Sensor.ino
    Air Pressure Sensor: https://github.com/TempeHS/TempeHS_Ardunio_Boilerplate/blob/main/TempeHS_Sensor_Catalogue/Sensor%20Kit/Air_Pressure_Sensor/Air_Pressure_Sensor.ino
*/

unsigned int myOLED = 12;

// temperature/air pressure
#include "Seeed_BMP280.h"

// include for oled display
#include <U8g2lib.h>

// for i2c
#include <Wire.h>
#include <Arduino.h>

// strings for oled
String myMessage = "First Line";
String myMessage2 = "Second Line";

// configure for oled display copied from libary
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);  // High speed I2C

// setup pressure sensor object
BMP280 bmp280;

void setup() {  
// begin oled
u8g2.begin();

// setup sm
Serial.begin(9600);
Serial.println("SM working to 9600 o/");
Serial.println("--------------------");

// begin comm with pressure sensor
if(!bmp280.init()){
    Serial.println("Device error!");

  }
}


void loop() {
// read air pressure
  float myPressure = bmp280.getPressure();
  float myTemp = bmp280.getTemperature();
  float myAltitude = bmp280.calcAltitude(myPressure);

  myMessage = "Good morning";
  myMessage2 = "Today's Temp is: " + String(myTemp) + "c";


printToOLED(myMessage, myMessage2);

}