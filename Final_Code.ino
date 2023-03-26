/*
Authors - Adit Chopra, Azaz ur Rehman Nasir, Sarah Farhat
FINAL TERM PROJECT: Catch me if you can!
ENGR-UH-1000 Computer Programming for Engineers
Date created: 13 October, 2021
Problem Statement: 
The program must take real time input of the orientation and accelaration of the M5 Core2 device
and use it to calculate the steps, accelaration (maximum during the journey) and the distance (in m) 
moved by the person. The distance moved, maximum acceleration and steps are printed on the screen of
the LCD screen of the M5 Stack Core2 module. Also, a button is programmed which would reset everything 
when pressed.
*/

// Including the necessary liibraries
#include <M5Core2.h>

// Define variables for storing sensor data of the acelerometer and initialize it to 0 
float accX = 0.0F;
float accY = 0.0F;
float accZ = 0.0F;

// Declare integer type variable "step" and set it to 0 
float step = 0;

// Declare float variable type "distance" and set it to 0
float distance = 0;

// Declaring float variable type "max_acc" and set it to 0
float max_acc = 0;

// Declaring a boolean variable type "flag" and put it as "false"
bool flag = false;

// Declaring a float type variable "ACC"
float ACC;

// Defining the structure of the time clock
RTC_TimeTypeDef TimeStruct;

/* 
After M5Core2 is started or reset
The code in the setUp() function will be run only once.
*/

void setup()
{
  // Setup of the M5 core 2 begins
  M5.begin();
  
  // IMU unit sensor is initiated
  M5.IMU.Init();  
  
  // Set the screen background color to BLACK.
  M5.Lcd.fillScreen(BLACK);

  // Set the foreground and background color of the displayed text as YELLOW and BLACK respectively.
  M5.Lcd.setTextColor(YELLOW , BLACK);

  //Set the font size to 2
  M5.Lcd.setTextSize(2);

  // Setting up the time in the M5 Core2 module
  TimeStruct.Hours   = 00;
  TimeStruct.Minutes = 00;
  TimeStruct.Seconds = 00;
  M5.Rtc.SetTime(&TimeStruct);
}

/* 
The code in loop() function is will run infinitely as we want to record user's every movement
*/

void loop() 
{  
  // Stores the triaxial accelerometer.
  M5.IMU.getAccelData(&accX,&accY,&accZ); 

  // Defining "ACC" which is defined as the distance between origin and point (accX,accY,accZ)
  ACC = sqrt(accX*accX + accY*accY + accZ*accZ);

  // Getting the time from the TimeStruct
  M5.Rtc.GetTime(&TimeStruct);    
  
  /* 
  The top left corner of the screen (0,0).
  Also, the screen of M5 Core 2 is 320 x 320 pixels
  */
  
  // Reads the present state of the A,B,C keys
  M5.update();
    
  // Steps Output
  M5.Lcd.setCursor(80, 56);
  M5.Lcd.print("Steps taken: ");
  M5.Lcd.setCursor(129, 78);
  M5.Lcd.print(step);

  // Distance output
  M5.Lcd.setCursor(18, 100);
  M5.Lcd.print("Distance travelled in m: ");
  M5.Lcd.setCursor(129, 122);
  M5.Lcd.print(distance);
  
  // For a certain value of "ACC" and "flag", steps is incremented by 1 and to avoid continous 
  // incrementation of the steps while value of "ACC" is greater than a threshold value, we also 
  // put "flag" as true to avoid getting into the loop again during the duration while "ACC" is greater than 1.6
  if (ACC > 1.6 && flag == false)
  {
    float i = random (51, 67);
    distance = distance + (i/100);
    step = step + 1;
    flag = true;
  }

  // Resetting the flag value to false when ACC falls below a threshold value
  else if (ACC < 1.3 && flag == true)
  {
    flag = false;
  }

  // If the value of "ACC" is greater than the value stored in "max_acc" then "max_acc" is updated
  if (ACC > max_acc)
  {
    max_acc = ACC;
  }

  // Accelaration output
  M5.Lcd.setCursor(0, 144);
  M5.Lcd.printf("Max Acc(in m/s): ");
  M5.Lcd.setCursor(195, 144);
  M5.Lcd.print(max_acc);
    
  // Button warning Output
  M5.Lcd.setCursor(0, 22);
  M5.Lcd.print("Press button B to reset");
  
  // If the button B was pressed and released after 700ms then the step, duration and distance are reset to 0
  if (M5.BtnB.wasReleasefor(700))
  {
    step = 0;
    distance = 0;
    max_acc = 0;
    // Dynamic part of the code
    setup(); // We again call the setup function so that everything resets if button B is pressed 
  }

  // Duration Output
  M5.Lcd.setCursor(0, 196);
  M5.Lcd.printf("Duration: %02d : %02d : %02d", TimeStruct.Hours, TimeStruct.Minutes, TimeStruct.Seconds);
  
  // We delay the loop for 65 ms so that the instantaneous error can be removed
  delay(65);
}
