# ROSMicrozoneBridge
a bridge between ROS and Microzone by rosserial bag

1 hardware list
Arduino Mega2560
MicroZone Receiver and tele-publisher(6 channels)

2 simple theory
measure high plus duartion time of channels' signal(time unit: us) by 6 Arduino external interrupt, which can save cpu resource and enhance accurancy of measurement.

this is rosMicrozoneBridge version2.0

Add communication function to ROS node, if you want to use the source code, you have to write rosmsg and rebuild roslib from rosserial_arduino bag, here offer serveral steps as follows:

1 make a file named selfmakemessage and a sub-file named msg
mkdir selfmakemessage/msg

2 come into file msg and create a  Microzone.msg file
touch Microzone.msg
3 open Microzone.msg and write in msg data structure
int ch1
int ch2
int ch3
int ch4
int ch5
int ch6

4 and then modify cmakelist, add the support to build
catkin_Make <your-package>

5 install ros-arduino-serial package
sudo apt-get install ros-indigo-rosserial-arduino
sudo apt-get install ros-indigo-rosserial
rospack profile

6 install rosserial
  cd <ws>/src
  git clone https://github.com/ros-drivers/rosserial.git
  cd <ws>
  catkin_make
  
7 produce roslib
 cd <arduino_lib_directory>
 rosrun rosserial_arduino make_libraries.py .
 
8 complete

if you have any problems in the tiny project, you can contact with me.
e-mail:zhi12271125@gmail.com


