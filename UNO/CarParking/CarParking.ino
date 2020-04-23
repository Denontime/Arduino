#include <Stepper.h>
 
// 电机内部输出轴旋转一周步数
const int STEPS_PER_ROTOR_REV = 32; 

//  减速比
const int GEAR_REDUCTION = 64;

// 电机外部输出轴旋转一周步数 （2048）
const float STEPS_PER_OUT_REV = STEPS_PER_ROTOR_REV * GEAR_REDUCTION;
 
// 电机旋转步数
int StepsRequired = 0;
int state;
 
Stepper steppermotor(STEPS_PER_ROTOR_REV, 8, 10, 9, 11); 
 
void setup()
{
  Serial.begin(9600);
  
  while (!Serial) {
    ; 
  }
  
  steppermotor.setSpeed(500);   
}
 
void loop()
{

  if(Serial.available() > 0){


      switch (Serial.read()) {
        case 'm':
          StepsRequired = Serial.parseInt();
          for(state=0;state<StepsRequired;state++){
            steppermotor.step(1);
          }
          Serial.println("m_done");
          break;
        case 's':
          state = Serial.parseInt();
          Serial.println(state);//显示屏代码
          break;
        default:
          Serial.println("nono");
          break;
      }

  }
}
