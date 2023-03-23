## <h1 align="center">Pedometer - Steps, Maximum Acceleration, and Distance </h1>
### Introduction
According to health professionals, daily walking and running is essential for living a healthy life. It helps us in the following manners\

● increased heart and lung fitness

● lower risk of heart disease and stroke.

● better management of conditions such as hypertension (high blood pressure), high cholesterol, joint and muscular pain, and diabetes

● stronger bones and improved balance

● increased muscle strength and endurance

● decreased body fat

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
Variables declared and used are:
● accX, accY, accZ: Float data type variables to store the accelerometer sensor data.\
● step: Float data type variable to stores the number of steps taken by user\
● max_acc: Float data type variable to stores the maximum acceleration of the user\
● distance: Float data type variable to store the distance travelled by user\
