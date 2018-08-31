#include "signalRead.h"

unsigned int* arr;

//*arr   *(arr+1) ...即为数组的元素
//Serial.print("\t");//输出元素之间有一定的间隔

void setup(){
  Serial.begin(115200); // Serial for debug
  PWMReadInit();//PWMRead function initial
}

void loop() {
  //Serial.println(singlePWMRead(1));
  arr = MixPWMRead();
  Serial.print(*arr);
  Serial.print("---");
  Serial.println(*(arr+1));
}

