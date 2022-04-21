/*
25 模拟输出1 - analogWrite
太极创客
www.taichi-maker.com

此程序用于太极创客<<零基础入门学用Arduino教程>> 
25 模拟输出1 - analogWrite

演示如何通过两个按键开关通过analogWrite指令
进行模拟输出操作。具体电路和其它信息请参考
太极创客网站本教程相关页面。

2017-04-28
*/
boolean pushButton1;   // 创建布尔型变量用来存储按键开关1的电平状态
boolean pushButton2;   // 创建布尔型变量用来存储按键开关2的电平状态
int ledPin = 9;        //LED引脚号
int brightness = 128;  //LED亮度参数

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP); //将引脚2设置为输入上拉模式
  pinMode(8, INPUT_PULLUP); //将引脚8设置为输入上拉模式
  pinMode(ledPin, OUTPUT);  //将LED引脚设置为输出模式
  Serial.begin(9600);      //启动串口通讯
}

void loop() {
  // put your main code here, to run repeatedly:
  pushButton1 = digitalRead(2); //读取引脚2电平状态并将其赋值给布尔变量
  pushButton2 = digitalRead(8); //读取引脚8电平状态并将其赋值给布尔变量
  
  if (!pushButton1 && brightness > 0){     // 当按下按键开关1并且LED亮度参数大于0
    brightness--;                          // 减低LED亮度参数
                                           //（brightness-- 相当于  brightness = brightness - 1;）
  } else if (!pushButton2 && brightness < 255) {  //当按下按键开关2并且LED亮度参数小于255
    brightness++;                                 //增加LED亮度参数
                                                  //（brightness++ 相当于  brightness = brightness + 1;）
  }
  analogWrite(ledPin, brightness);         //模拟输出控制LED亮度
  Serial.println(brightness);              //将LED亮度参数显示在串口监视器上
  delay(10);
}
