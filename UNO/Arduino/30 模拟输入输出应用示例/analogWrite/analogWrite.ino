/*
  电位器模拟输出
 
 读取模拟输入引脚，并将读取到的数值映射到0 - 255之间。然后用该映射结果设置
 引脚9的LED亮度，同时通过串口监视器显示这一映射结果。
 
 电路连接:
     电位器中间引脚连接到模拟输入A0引脚
     电位器两端引脚分别连接在Arduino +5V和接地引脚
   * LED正极通过 限流电阻连接在Arduino的9号引脚
     LED负极接地
 
 太极创客
 2017-01-08
 <blockquote data-secret="W1T9d0SaZ7" class="wp-embedded-content"><a href="http://www.taichi-maker.com/">欢迎来到太极创客网站!</a></blockquote><iframe class="wp-embedded-content" sandbox="allow-scripts" security="restricted" style="position: absolute; clip: rect(1px, 1px, 1px, 1px);" src="http://www.taichi-maker.com/embed/#?secret=W1T9d0SaZ7" data-secret="W1T9d0SaZ7" width="600" height="338" title="《欢迎来到太极创客网站!》—太极创客" frameborder="0" marginwidth="0" marginheight="0" scrolling="no"></iframe>
 
 This example code is in the public domain.
 
 */
 
void setup() {
   
  Serial.begin(9600);  // 串口通讯初始化(9600 bps)
  pinMode(9, OUTPUT);  // 设置9号引脚为输出模式
}
 
void loop() {
  int analogInputVal = analogRead(A0);  // 读取模拟输入值
 
  int brightness = map(analogInputVal, 0, 1023, 0, 255); //将模拟输入数值（0 - 1023）等比映射到模拟输出数值区间（0-255）内
   
  analogWrite(9, brightness);  //根据模拟输入值调节LED亮度
 
  // 将结果通过串口监视器显示:
  Serial.print("analogInputVal = ");
  Serial.println(analogInputVal);
   
  Serial.print("brightness = ");
  Serial.println(brightness);
   
  Serial.println("");
}
