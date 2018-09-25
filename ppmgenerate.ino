/* 方向电机不受驱动开关影响，而只控制后轮驱动电机
 * dir min=1000,max=1900,mid=1500
 * acc min=1000,max=1900,mid=1500～1780
 * 转向电机左转为正，右转为负方向
 * 1000<--------1500------->1900
 * 左转<---------回正-------->右转
 * 
 * 驱动电机前进为正，后退为负方向
 *       /|\  1000   前进
 *        |
 *       死区  1500~1780   停止
 *        |
 *        |
 *       \|/  1900   后退
 * 
 */

#include <Servo.h>

Servo servoDir;
Servo servoAcc;

#define dirPin 8   //方向电机控制引脚
#define accPin 9   //驱动电机控制引脚
#define ppmMax 1900  //输入的最大PPM信号
#define ppmMin 1000  //输入的最小PPM信号
#define dirPpmMid 1500 //方向电机回正PPM值
#define accPpmMid 1550 //驱动电机回零PPM值
#define accDeadBandMax 1780 //驱动电机最大死区PPM值
#define accDeadBandMin 1500 //驱动电机最小死区PPM值

unsigned long initTime = 10000;  //初始化时间为10s


unsigned long times = 0;

void initDriver(){
  servoDir.attach(dirPin);
  servoAcc.attach(accPin);
  
  servoDir.writeMicroseconds(dirPpmMid);
  servoAcc.writeMicroseconds(accPpmMid);
}

void stopDriver(){
  initDriver();
}

void dirMotor(int dirMotorAng){//输入信号dirMotorAng的范围是[-400,500] 正为左转，负为右转
  int dirMotorSig = dirPpmMid - dirMotorAng;//将输入的转向信号，转化成1000-1900的PPM信号
  //限位判断
  if(dirMotorSig > ppmMax){
    dirMotorSig = ppmMax;
  }
  if(dirMotorSig < ppmMin){
    dirMotorSig = ppmMin;
  }
  servoDir.writeMicroseconds(dirMotorSig);
}

void accMotor(int accMotorSpd){//输入信号accMotorSpd的范围是[-120,500] 正为前进，负为后退
  int accMotorSig;
  if(accMotorSpd>=0){//前进
    accMotorSig = accDeadBandMin - accMotorSpd;
  }
  else{//后退
    accMotorSig = accDeadBandMax - accMotorSpd;
  }

  //限速设置
  if(accMotorSig > ppmMax){
    accMotorSig = ppmMax;
  }
  if(accMotorSig < ppmMin){
    accMotorSig = ppmMin;
  }
  servoAcc.writeMicroseconds(accMotorSig);
}

void setup() {
  // put your setup code here, to run once:
  initDriver();
  //delay(10000);
  
  times = millis();
}

void loop() {
  while((millis() - times) < 10000){
    initDriver();
  }

  while((millis() - times) < 20000){
    dirMotor(200);
    accMotor(200);
  }
  initDriver();
  while((millis() - times) < 40000){
    dirMotor(-200);
    accMotor(-100);
  }
  stopDriver();
}
