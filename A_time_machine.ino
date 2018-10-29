#include <InvertedTM1638.h>
#include <TM1638.h>
#include <TM1638QYF.h>
#include <TM1640.h>
#include <TM16XX.h>
#include <TM16XXFonts.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define TM1638_STB 5
#define TM1638_CLK 6
#define TM1638_DIO 7

#define OLED_MOSI 11
#define OLED_CLK 13
#define OLED_DC 9
#define OLED_CS 12
#define OLED_RESET 10

//allows me to use the servo
#include <Servo.h>

byte buttons;
TM1638 module (TM1638_DIO, TM1638_CLK, TM1638_STB);
Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS);   //used for the screen
Servo myservo; // creates the servo object


void setup()
{
module.clearDisplay();
module.setupDisplay(true,2);

myservo.attach(3);  //the servo object is connected via pin 3

 display.begin(SSD1306_SWITCHCAPVCC);
 display.display();
 delay(1000);
 display.clearDisplay();
 display.setTextSize(2.5);
 display.setTextColor(WHITE);

 
}
void loop() {
  for ( int i = 0; i <= 60; i++)
  {
    module.setDisplayToDecNumber(i,0,false);
    display.clearDisplay();
    display.setCursor(0,0);

if (i == 10)
{
  bool awake = false;
  do{
  int pos = 0;    // variable to store the servo position
  for (pos = 0; pos <= 180; pos += 1) 
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(1000);                       // waits 15ms for the servo to reach the position
  }
  }while(awake == false);
  
  display.print("Alarm : ");

    display.print(i);
    display.display();
    delay(1000); // do nothing
    
  if (module.getButtons() == 1)
    {awake = true;}
 
}
  } 
  }
