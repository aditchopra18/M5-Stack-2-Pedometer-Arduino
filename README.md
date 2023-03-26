## <h1 align="center">Pedometer - Steps, Maximum Acceleration, and Distance </h1>
### Introduction
According to health professionals, daily walking and running is essential for living a healthy life. It helps us in the following manners\
● Increased heart and lung fitness\
● Lower risk of heart disease and stroke\
● Better management of conditions such as hypertension (high blood pressure), high cholesterol, joint and muscular pain, and diabetes\
● Stronger bones and improved balance\
● Increased muscle strength and endurance\
● Decreased body fat

Pedometers are inexpensive and dependable. Anyone, from children to adults, can easily wear track their running and walking activity through pedometers.

## Project Description
### Device Used
M5 Stack Core 2 Module

### Software Used
Arduino

### Libraries Utilized
M5Core2

### Sensors Used
The 6-axis IMU sensor (MPU 6886) of M5 Stack Core 2

### Problem Statement
The device's program must take real time input of the orientation and accelaration of the M5 Core 2 device and use it to calculate the steps, accelaration (maximum during the journey) and the distance (in m) moved by the person. The distance moved, maximum acceleration and steps are printed on the screen of the LCD screen of the M5 Stack Core2 module. Also, a button is programmed on the device which would reset everything when pressed.

## Project Implementation
The implementation of the entire project is detailed below. It has explanations about every step used in the project

### Headers Files and Declaration of Variables
● "M5Core2.h" is imported\
Variables declared and used are:\
● accX, accY, accZ: Float data type variables to store the accelerometer sensor data.\
● step: Float data type variable to stores the number of steps taken by user\
● max_acc: Float data type variable to stores the maximum acceleration of the user\
● distance: Float data type variable to store the distance travelled by user\

### Code's Working Methodology
The Pedometer we developed is based on the principle that whenever a person takes a step, the acceleration of the person changes and then decreases. By defining a threshold maximum acceleration, a threshold minimum acceleration, and a Boolean variable “flag” which is initially set to “false”, we were able to calculate the number of steps without any complex coding. Whenever the person moves, his/her acceleration increases and crosses the maximum acceleration threshold. If the “flag” is false, a step is incremented by 1, distance is added and then to avoid continuous incrementation, the “flag” set to true. When the acceleration of the person falls below the minimum acceleration threshold, the “flag” is again set to false to record the next step.\
The acceleration is calculated by the MPU 6886 IMU sensor in the M5 Stack Core 2 and the respective accelerations in x, y, z axes are taken and by vector addition, the magnitude of total acceleration is recorded. The in-built clock in M5 Stack Core 2 is set to zero when the program starts. The button is programmed in such a way that if pressed and released after 700 ms, the journey resets.

## Results and Evaluation
The project was tested by people under different conditions. Following are the conditions under which our project has been tested and given successful results.
1) Normal walking
2) Climbing up and down a staircase
3) Running

## Challenges Faced
1) The first challenge was that any three-dimensional body’s rotation can be described as the superposition of the 3 rotations about its x, y, and z axes. Hence, programming the M5 Stack Core 2 to count the steps in any orientation while it is kept in pocket was a difficult task.
2) Measuring the maximum acceleration of the user was a huge task because initially we were unable to define what was the maximum acceleration of the person.
3) Measuring and synching the clock to 00:00:00 when it begins or when reset was a challenge.

## Debugging Methodologies used
### Debugging by Printing Statements
Whenever a logical error came up, the concerned values were printed separately on a screen. That's how I knew where I was going wrong. Below is a photo where I printed the values of the pitch, roll, yaw and acceleration in "x", "y", "z" direction respectively to test whether the sensors were working properly or not. 

### Debugging by Error Handling
A code crashes when there is some error in it. The output terminal of the Arduino would display an error if something was wrong in the code. Below is a photo when a syntax error while writing the code caused it to display the error.

### Debugging by Commenting
In order to identify the part of the code which is causing the error, I would comment different parts of the code in order to find the error.

## Project Achievements
- RESPONSIVE : It is able to detect even the shortest of steps and is tested under variety of conditions
- ACCURATE : The distance calculated is accurate up to 1/100th of a meter.
- SIMPLE TO USE : The one-touch reset button and its accuracy make this project a cheaper and an easier alternative to the existing Pedometers.

## POTENTIAL FUTURE DEVELOPMENTS
- By including additional libraries, we can even measure the heart rate of the individual by maybe measuring the pulse and filtering the data and showing it on the screen
- By taking the input of weight from the user, we can even show the number of calories burnt by the person during his/her journey.
- By including other libraries, we can take the input from user about the target steps/distance they want to achieve and play a ding-dong sound or vibrate when the target is achieved.
- By further coding, the Graphic user interface can be improved in such a way that the user is easily able to understand how to use it and even display a “Welcome message”, etc.
- By including other libraries, we can also create different modes within the M5 Stack Core 2 like a separate mode for running, walking, hiking, and much more.
