#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET     4
int tourSwipe = 0;
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);
Servo ROTATING_BASE;//create servo object to control a servo
Servo SHOULDER;
Servo ELBOW;

void setup()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextColor(WHITE);//Sets the font display color
  display.clearDisplay();//cls

  ROTATING_BASE.attach(10);//attachs the servo on pin 9 to servo object
  SHOULDER.attach(11);
  ELBOW.attach(3);

  ROTATING_BASE.write(0);//back to 0 degrees
  SHOULDER.write(0);
  ELBOW.write(0);
  SHOULDER.write(180);//goes to 15 degrees
  ELBOW.write(100);//goes to 15 degrees

  


  

  delay(4000);//wait for a 

  







  
}
void loop()
{
tourSwipe++;
  
  display.clearDisplay();//cls
  //Set the font size
  display.setTextSize(1);
  //Set the display location
  display.setCursor(0, 0);
  //String displayed
  display.print("Nb views :");
  display.setTextSize(2);
  display.setCursor(0, 40);
  display.print(tourSwipe);
  //Began to show
  display.display();

  // Move
  for (int i = 30; i >= 0; i--) // decrementally move back to 0 degrees
  {
    ROTATING_BASE.write(i);
    delay(20); // adjust the delay as needed for a smoother motion
  }
  delay(1000);

  // up
  ELBOW.write(80);
  delay(1000);
  SHOULDER.write(180);
  delay(1000);

  // up
  ELBOW.write(80);
  delay(1000);
  SHOULDER.write(170);
  delay(1000);

  // Move
  for (int i = 0; i <= 30; i++) // incrementally move to 50 degrees
  {
    ROTATING_BASE.write(i);
    delay(40); // adjust the delay as needed for a smoother motion
  }
  delay(1000);

  // Click
  ELBOW.write(80);
  delay(1000);
  SHOULDER.write(180);
  delay(1000);
  
  // up
   ELBOW.write(80);
  delay(1000);
  SHOULDER.write(170);
  delay(1000);

  delay(1000);//wait for a second.33

}


void swipe_robot_arm() {
  for (int i = 30; i >= 0; i--) // decrementally move back to 0 degrees
  {
    ROTATING_BASE.write(i);
    delay(20); // adjust the delay as needed for a smoother motion
  }

  
  delay(1000);//wait for a second.33
  ELBOW.write(80);


  //  SHOULDER.write(180);//goes to 30 degrees
  for (int i = 170; i <= 180; i++) // incrementally move back to 180 degrees
  {
    SHOULDER.write(i);
    delay(80); // adjust the delay as needed for a smoother motion
  }

  delay(2000);//wait for a second.33

  for (int i = 0; i <= 30; i++) // incrementally move to 50 degrees
  {
    ROTATING_BASE.write(i);
    delay(40); // adjust the delay as needed for a smoother motion
  }

  delay(1000);//wait for a second.33
  ELBOW.write(80);

  delay(500); // wait for a short duration
  for (int i = 180; i >= 170; i--) // decrementally move to 170 degrees
  {
    SHOULDER.write(i);
    delay(20); // adjust the delay as needed for a smoother motion
  }

  delay(1000);//wait for a second.33
  ELBOW.write(80);


  //  SHOULDER.write(180);//goes to 30 degrees
  for (int i = 170; i <= 180; i++) // incrementally move back to 180 degrees
  {
    SHOULDER.write(i);
    delay(80); // adjust the delay as needed for a smoother motion
  }

  
}
