/*
 * 布尔变量应用示例
 * 
 * 本示例程序演示如何使用布尔型数据变量。通过本程序，Arduino将利用
 * 布尔型变量存储引脚2的电平状态，并根据变量数值点亮或熄灭引脚13上
 * 连接的LED。
 * 
 * 电路：
 * 引脚2连接轻触开关，开关另一端接地
 * 引脚13上安装有开发板内置LED
 * 
 * 
 * This example code is in the public domain
 * 太极创客 
 * 2017-01-18
 * www.taichi-maker.com
*/
boolean pushButton; // 创建布尔型变量
 
void setup() {
  pinMode(2, INPUT_PULLUP); //将引脚2设置为输入上拉模式
  pinMode(13, OUTPUT);      //将引脚13设置为输出模式
}
 
void loop() {
  pushButton = digitalRead(2); //读取引脚2电平状态并将其赋值给布尔变量
   
  if (pushButton){          //根据布尔变量数值点亮或者熄灭LED
    digitalWrite(13, HIGH); //布尔变量数值为真（true）时点亮LED
  } else {
    digitalWrite(13, LOW);  //布尔变量数值为假（false）时熄灭LED
  }
}
