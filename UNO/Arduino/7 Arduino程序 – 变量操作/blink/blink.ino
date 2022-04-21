/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
  反复的点亮LED一秒钟，然后关闭LED一秒钟。
 
  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO 
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
  很多Ａｒｄｕｉｎｏ开发板上带有一个你可以控制的ＬＥＤ． 在UNO, MEGA 和 ZERO型号的开发板上，
  这个ＬＥＤ连在了引脚１３上。 在MKR1000型号的开发板上，这个ＬＥＤ连在了引脚６上。无论使用哪
  种型号的开发板，LED_BUILTIN可以代表正确的LED引脚编号。
   
  This example code is in the public domain.
 
  modified 8 May 2014
  by Scott Fitzgerald
   
  modified 2 Sep 2016
  by Arturo Guadalupi
   
  modified 8 Sep 2016
  by Colby Newman
 
  注释中文翻译：太极创客
  www.taichi-maker.com
*/
 
 int delayTime;
 
// the setup function runs once when you press reset or power the board
//当你给开发板通电后或者按下复位按钮后，setup函数运行一次。
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  // 初始化LED_BUILTIN数字引脚为输出模式
  pinMode(LED_BUILTIN, OUTPUT);
}
 
// the loop function runs over and over again forever
// loop 函数永远会反复的运行
void loop() {
  delayTime = delayTime + 1000;
  digitalWrite(LED_BUILTIN, HIGH);   // 点亮LED（高电平）turn the LED on (HIGH is the voltage level)
  delay(1000);                       // 等待1秒 wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // 将电平设置为低来熄灭LED turn the LED off by making the voltage LOW
  delay(1000);                       // 等待1秒 wait for a second
}
