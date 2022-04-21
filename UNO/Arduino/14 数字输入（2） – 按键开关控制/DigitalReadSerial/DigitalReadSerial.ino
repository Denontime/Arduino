/*
 DigitalReadSerial
 Reads a digital input on pin 2, prints the result to the serial monitor
 读取引脚2的数字输入，将结果显示在串口监视器中
 
 This example code is in the public domain.
 */
 
// digital pin 2 has a pushbutton attached to it. Give it a name:
//引脚2连接有按键开关，给它一个名字：
int pushButton = 2;
 
// the setup routine runs once when you press reset:
//当你按下复位按钮后，setup流程运行一次：
void setup() {
  // initialize serial communication at 9600 bits per second:
  //串口通讯初始化，每秒9600位
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  //设置按键引脚为输入
  pinMode(pushButton, INPUT);
}
 
// the loop routine runs over and over again forever:
// loop 流程会永远的反复运行
void loop() {
  // read the input pin:
  //读取输入引脚:
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  // 显示按键状态
  Serial.println(buttonState);
  delay(1);        // delay in between reads for stability 为确保程序稳定运行进行短暂停止
}
