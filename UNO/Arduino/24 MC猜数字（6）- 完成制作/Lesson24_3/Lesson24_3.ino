/*
24 MC猜数字 - 5 完成制作 - 3
太极创客
www.taichi-maker.com

此程序用于太极创客<<零基础入门学用Arduino教程>> 
24 MC猜数字 - 5 完成制作 - 3

每次按键后闪动随机图案，最后停留在一个数字上面
此版本已基本实现猜数字游戏装置功能。

2017-04-23
*/
int myNumber;

void setup() {
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
  int pinNumber = 3;
  while(pinNumber <= 9){
    pinMode(pinNumber, OUTPUT);
    pinNumber = pinNumber + 1;
  }
  randomSeed(analogRead(A0));
}

// the loop function runs over and over again forever
void loop() {
  if (!digitalRead(2)){
    myNumber = getRandomNumber(0, 10);
  }
  displayNumber(myNumber);
}
int getRandomNumber(int minNumber, int maxNumber){
  int randomNumber;
  
  int i; 
  while(i < 15){
    i = i + 1;
    randomNumber = random(minNumber,maxNumber);
    //displayNumber(randomNumber);
    displayRandom();
    delay(100);
    displayClear();
    delay(100);

    Serial.print("i = ");
    Serial.println(i);
    Serial.print("randomNumber = ");
    Serial.println(randomNumber);
    Serial.println("");
  }
  return randomNumber;
}

void displayNumber(int ledNumber){
  switch(ledNumber){
    case 1:  //显示1
      digitalWrite(4, HIGH);
      digitalWrite(7, HIGH); 
      break;   
    case 2:  //显示2
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH); 
      digitalWrite(5, HIGH); 
      digitalWrite(8, HIGH); 
      digitalWrite(9, HIGH); 
      break;   
    case 3:   //显示3
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH); 
      digitalWrite(5, HIGH); 
      digitalWrite(7, HIGH); 
      digitalWrite(8, HIGH); 
      break;   
    case 4:  //显示4
      digitalWrite(4, HIGH); 
      digitalWrite(5, HIGH); 
      digitalWrite(6, HIGH); 
      digitalWrite(7, HIGH); 
      break;  
    case 5:  //显示5
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH); 
      digitalWrite(6, HIGH); 
      digitalWrite(7, HIGH); 
      digitalWrite(8, HIGH); 
      break;
    case 6:  //显示6
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH); 
      digitalWrite(6, HIGH); 
      digitalWrite(7, HIGH); 
      digitalWrite(8, HIGH); 
      digitalWrite(9, HIGH); 
      break;    
    case 7:  //显示7
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH); 
      digitalWrite(7, HIGH);  
      break;
    case 8:  //显示8
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH); 
      digitalWrite(6, HIGH); 
      digitalWrite(7, HIGH); 
      digitalWrite(8, HIGH); 
      digitalWrite(9, HIGH); 
      break;
    case 9:  //显示9
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH); 
      digitalWrite(6, HIGH); 
      digitalWrite(7, HIGH); 
      digitalWrite(8, HIGH); 
      break;
    case 0:  //显示默认
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(6, HIGH); 
      digitalWrite(7, HIGH); 
      digitalWrite(8, HIGH); 
      digitalWrite(9, HIGH); 
      break;
    default:
        digitalWrite(4, HIGH); 
        digitalWrite(5, HIGH); 
        digitalWrite(7, HIGH); 
        digitalWrite(8, HIGH);  
        digitalWrite(9, HIGH);   
    }
}

void displayClear(){
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW); 
  digitalWrite(6, LOW); 
  digitalWrite(7, LOW); 
  digitalWrite(8, LOW); 
  digitalWrite(9, LOW); 
}

void displayRandom(){
  int randomPin = random(3,9);
  digitalWrite(randomPin, HIGH);  
}
