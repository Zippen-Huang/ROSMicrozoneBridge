#include <ros.h>
#include <selfmakemessage/Microzone.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>

#include "signalRead.h"

ros::NodeHandle nh;

selfmakemessage::Microzone  Microzone_msg;
ros::Publisher MicrozonePublish("Microzone", &Microzone_msg);

unsigned int* arr;

//*arr   *(arr+1) ...即为数组的元素
//Serial.print("\t");//输出元素之间有一定的间隔

void setup(){
//  Serial.begin(115200); // Serial for debug
  PWMReadInit();//PWMRead function initial
  
  nh.initNode();
  nh.advertise(MicrozonePublish);
}

void loop() {
  //Serial.println(singlePWMRead(1));
  arr = MixPWMRead();//read pwm signal

  Microzone_msg.ch1 = (*arr);
  Microzone_msg.ch2 = *(arr+1);
  Microzone_msg.ch3 = *(arr+2);
  Microzone_msg.ch4 = *(arr+3);
  Microzone_msg.ch5 = *(arr+4);
  Microzone_msg.ch6 = *(arr+5);

  MicrozonePublish.publish(&Microzone_msg);

  nh.spinOnce();
  //Serial.println(*arr);

//  nh.logdebug(debug);
     nh.loginfo("in loop");
//  nh.logwarn(warn);
//  nh.logerror(error);
//  nh.logfatal(fatal);
}

