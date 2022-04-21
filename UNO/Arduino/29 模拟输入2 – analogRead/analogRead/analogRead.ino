/*
  模拟输入
 
  本程序旨在演示如何使用analogRead()读取Arduino的引脚电平。
  通过调节电位器， A0引脚的输入电压将在0V－5V之间。
  该输入电压将被映射到数值0-1023之间，并显示在串口监视器中。
   
 电路连接:
   电位器中间引脚连接到模拟输入A0引脚
   电位器两端引脚分别连接在Arduino +5V和接地引脚
 
 太极创客 www.taichi-maker.com
 2017-01-08
 
 This example code is in the public domain.
 
 */
 
void setup() {
  // 串口通讯初始化(9600 bps):
  Serial.begin(9600);
}
 
void loop() {
  // 读取模拟输入值:
  int analogInputVal = analogRead(A0);
 
  // 将结果通过串口监视器显示:
  Serial.println(analogInputVal);
}
