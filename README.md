# ROSMicrozoneBridge
a bridge between ROS and Microzone by rosserial bag

1 hardware list
Arduino Mega2560
MicroZone Receiver and tele-publisher(6 channels)

2 simple theory
measure high plus duartion time of channels' signal(time unit: us) by 6 Arduino external interrupt, which can save cpu resource and enhance accurancy of measurement.


this version is 1.0.

code version1.0: just finished read 6 high plus duartion time of signal, and put them into array, so you can read these data out of array by pointer.
code version2.0: finished to send signal array data to ROS, if you want to use my code resource, just install ros-<distro>-serial package(see roswiki official website), and create a *.msg file whose format is same to arduino's. 

if you have any problems in the tiny project, you can contact with me.
e-mail:zhi12271125@gmail.com
