 // function to update oled display
 void printToOLED(float theTemp, float thePressure) {
  u8g2.clearBuffer();                   // clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr);   // choose a suitable font
  u8g2.setCursor(0,10);
  u8g2.print("Hello world o/");
  u8g2.setCursor(0,20);
  u8g2.print("Today temp is: ");
  u8g2.print(theTemp);
  u8g2.print("c");
  u8g2.setCursor(0,30);
  u8g2.print("The pressure is: ");
  u8g2.print(thePressure);
  u8g2.print("hp");
  u8g2.setCursor(0,40);
  if (thePressure > 1005) {
    u8g2.print("STORM WARNING");
  } else {
    u8g2.print("GOOD WEATHER");
  }
*/
  u8g2.sendBuffer();

}
float myTemp() {
  return bmp280.getTemperature();
}

float myPressure() {
  return bmp280.getPressure();
}