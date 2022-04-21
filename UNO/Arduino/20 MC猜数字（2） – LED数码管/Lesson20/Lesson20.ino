/*
20 MC猜数字 - 2 LED数码管 
太极创客
www.taichi-maker.com

此程序用于太极创客<<零基础入门学用Arduino教程>>
20 MC猜数字 - 2 LED数码管 
课程的演示实验使用。

2017-04-21
*/

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

}

// the loop function runs over and over again forever
void loop() {
   
   // 显示 1:
    digitalWrite(4, HIGH);
    digitalWrite(7, HIGH); 
    delay(500);  

  // 清理显示内容
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW); 
    digitalWrite(6, LOW); 
    digitalWrite(7, LOW); 
    digitalWrite(8, LOW); 
    digitalWrite(9, LOW); 
    delay(500);
    
  // 显示 2:
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH); 
    digitalWrite(5, HIGH); 
    digitalWrite(8, HIGH); 
    digitalWrite(9, HIGH); 
    delay(500);
      
  // 清理显示内容
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW); 
    digitalWrite(6, LOW); 
    digitalWrite(7, LOW); 
    digitalWrite(8, LOW); 
    digitalWrite(9, LOW); 
    delay(500);
       
  // 显示 3:
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH); 
    digitalWrite(5, HIGH); 
    digitalWrite(7, HIGH); 
    digitalWrite(8, HIGH); 
    delay(500);  

  // 清理显示内容
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW); 
    digitalWrite(6, LOW); 
    digitalWrite(7, LOW); 
    digitalWrite(8, LOW); 
    digitalWrite(9, LOW); 
    delay(500);
}








