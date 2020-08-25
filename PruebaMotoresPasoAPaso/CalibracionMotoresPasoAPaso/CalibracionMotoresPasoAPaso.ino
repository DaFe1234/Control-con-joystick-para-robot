// Para Base driver eje X STEP 5 y DIR 2 / Para Codo driver eje z STEP 7 y DIR 4 / Para Hombro eje y STEP 6 y DIR 3
#include <Arduino.h>
#include "BasicStepperDriver.h"

// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 256
#define RPM 70





// Since microstepping is set externally, make sure this matches the selected mode
// If it doesn't, the motor will move at a different RPM than chosen
// 1=full step, 2=half step etc.
#define MICROSTEPS 2

// eje X
#define DIR_x 2
#define STEP_x 5
// eje Y
#define DIR_y 3
#define STEP_y 6
// eje Z
#define DIR_z 4
#define STEP_z 7


// 2-wire basic config, microstepping is hardwired on the driver
BasicStepperDriver stepper_x(MOTOR_STEPS, DIR_x, STEP_x);
BasicStepperDriver stepper_y(MOTOR_STEPS, DIR_y, STEP_y);
BasicStepperDriver stepper_z(MOTOR_STEPS, DIR_z, STEP_z);


void setup() {
    stepper_x.begin(RPM, MICROSTEPS);
    stepper_y.begin(RPM, MICROSTEPS);
    stepper_z.begin(RPM, MICROSTEPS);

}

void loop() {

  ActivarMotores(1);
  MoverMotores(90,8);

}
void MoverMotores(int Grados, int Selector)
  
      if(Selector == 1){
       Grados =  map (Grados, -100 , 100 , -180*16 , 180*16);
       stepper_x.rotate(Grados);
      }
      if(Selector == 2){
       Grados =  map (Grados, -100 , 100 , -90*10 , 90*10);
       stepper_y.rotate(Grados);
      }
      if(Selector == 3){
       Grados =  map (Grados, -100 , 100 , -90*7 , 90*7);
       stepper_z.rotate(Grados);
      }
}
void ActivarMotores(bool Activar ){

   pinMode(8,OUTPUT);
   // Simbolo ! para negar 
   digitalWrite(8,!Activar);
}
