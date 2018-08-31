/*
E6-A编号----Mage引脚号----对应摇杆动作------------------------------------原点值--------------（极限值）
  1------------2------------偏航（右手-左右拨动）无人机左右原地旋转-----1500-1504----左：1740-1744|右：1260-1264
  2------------3------------前进后退（左手-前后拨动）无人机前进后退-----1484-1488----前：1248-1252|后：1728-1732
  3------------18-----------油门（右手-前后拨动）无人机上下飞动---------1584-1588----前：1104-1108|后：1988-1992
  4------------19-----------左进右进（左手-左右拨动）无人机左右飞动-----1500-1504----左：1256-1260|右：1660-1664
  5------------20-----------SWITCH POSITION（上拨-992；下拨-1992）
  6------------21-----------VR POSITION(992-1992)
  补充：A:D/R--4号通道--信号变化（上拨：1348---下拨：1404）
 */

#include "PWM.hpp"
unsigned int signalArray[6];//储存6个信道的PWM值

PWM ch1;
PWM ch2;
PWM ch3;
PWM ch4;
PWM ch5;
PWM ch6;

void PWMReadInit(){//  1代表读取高电平
  ch1.begin(2, 1); // ch1 on pin 2 reading PWM HIGH duration
  ch2.begin(3, 1); // ch2 on pin 3 reading PWM HIGH duration
  ch3.begin(18, 1); // ch3 on pin 18 reading PWM HIGH duration
  ch4.begin(19, 1); // ch4 on pin 19 reading PWM HIGH duration
  ch5.begin(20, 1); // ch5 on pin 20 reading PWM HIGH duration
  ch6.begin(21, 1); // ch6 on pin 21 reading PWM HIGH duration
}

unsigned int singlePWMRead(unsigned char num){//读取相应的单通道PWM值
  unsigned char ChannelNum = num;
  switch (ChannelNum){
    case 1:
        return ch1.getValue();
        break;
    case 2:
        return ch2.getValue();
        break;
    case 3:
        return ch3.getValue();
        break;
    case 4:
        return ch4.getValue();
        break;
    case 5:
        return ch5.getValue();
        break;
    case 6:
        return ch6.getValue();
        break;
    default:
        break;
  }
}

unsigned int* MixPWMRead(){
  signalArray[0] = ch1.getValue();
  signalArray[1] = ch2.getValue();
  signalArray[2] = ch3.getValue();
  signalArray[3] = ch4.getValue();
  signalArray[4] = ch5.getValue();
  signalArray[5] = ch6.getValue();
  return signalArray;
}

//调用数组函数
//unsigned int* arr；
//arr = MixPWMRead();
//*arr   *(arr+1) ...即为数组的元素
//Serial.print("\t");//输出元素之间有一定的间隔
