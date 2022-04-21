/*
 * 逻辑与布尔运算
 * 
 * 本示例程序演示逻辑与布尔运算。通过本程序，Arduino将对引脚2和引脚8的电平状态
 * 进行逻辑与布尔运算，并根据运算结果点亮或熄灭引脚13上连接的LED。
 * 
 * 电路：
 * 引脚2连接按键开关1，开关1另一端接地
 * 引脚8连接按键开关2，开关2另一端接地
 * 引脚13上安装有开发板内置LED
 * 
 * 
 * This example code is in the public domain
 * 太极创客 
 * 2017-01-18
 * www.taichi-maker.com
*/
 
boolean pushButton1; // 创建布尔型变量用来存储按键开关1的电平状态
boolean pushButton2; // 创建布尔型变量用来存储按键开关2的电平状态
 
void setup() {
  pinMode(2, INPUT_PULLUP); //将引脚2设置为输入上拉模式
  pinMode(8, INPUT_PULLUP); //将引脚8设置为输入上拉模式
  pinMode(13, OUTPUT);      //将引脚13设置为输出模式
}
 
void loop() {
  pushButton1 = digitalRead(2); //读取引脚2电平状态并将其赋值给布尔变量
  pushButton2 = digitalRead(8); //读取引脚8电平状态并将其赋值给布尔变量
   
  if (!pushButton1 && !pushButton2){  //根据逻辑与运算结果点亮或者熄灭LED
    digitalWrite(13, HIGH);           //两个布尔变量数值都为假（false）时点亮LED
  } else {
    digitalWrite(13, LOW);            //否则熄灭LED
  }
}
 
/*
逻辑与运算说明
!pushButton1 = 1, !pushButton2 = 1 --->  !pushButton1 && !pushButton2 = 1
!pushButton1 = 0, !pushButton2 = 1 --->  !pushButton1 && !pushButton2 = 0
!pushButton1 = 1, !pushButton2 = 0 --->  !pushButton1 && !pushButton2 = 0
!pushButton1 = 0, !pushButton2 = 0 --->  !pushButton1 && !pushButton2 = 0
*/
