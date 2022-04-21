/*
22 MC猜数字 - 4 switch case语句(3) switch

太极创客
www.taichi-maker.com

此程序用于太极创客<<零基础入门学用Arduino教程>>
22 MC猜数字 - 4 switch case语句
课程的演示实验使用。

2017-04-21
*/

void setup() {
  int pinNumber = 3;
  while(pinNumber <= 9){
    pinMode(pinNumber, OUTPUT);
    pinNumber = pinNumber + 1;
  }
}

// the loop function runs over and over again forever
void loop() {
   int myNumber = 9;
   switch(myNumber) { 
      case 1: //显示1
        digitalWrite(4, HIGH);
        digitalWrite(7, HIGH); 
        break;   
      case 2: //显示2
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH); 
        digitalWrite(5, HIGH); 
        digitalWrite(8, HIGH); 
        digitalWrite(9, HIGH); 
        break;   
      case 3: //显示3
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH); 
        digitalWrite(5, HIGH); 
        digitalWrite(7, HIGH); 
        digitalWrite(8, HIGH); 
        break;   
	  default:
        digitalWrite(4, HIGH); 
        digitalWrite(5, HIGH); 
        digitalWrite(7, HIGH); 
        digitalWrite(8, HIGH);  
        digitalWrite(9, HIGH);
    }
}
