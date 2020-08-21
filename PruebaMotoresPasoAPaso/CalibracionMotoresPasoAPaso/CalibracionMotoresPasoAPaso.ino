#include <Arduino.h>
#include "BasicStepperDriver.h"

// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 256
#define RPM 70





// Since microstepping is set externally, make sure this matches the selected mode
// If it doesn't, the motor will move at a different RPM than chosen
// 1=full step, 2=half step etc.
#define MICROSTEPS 2

// All the wires needed for full functionality
#define DIR 2
#define STEP 5

//Uncomment line to use enable/disable functionality
//#define SLEEP 13

// 2-wire basic config, microstepping is hardwired on the driver
BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP);

//Uncomment line to use enable/disable functionality
//BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP, SLEEP);

void setup() {
    stepper.begin(RPM, MICROSTEPS);
    // if using enable/disable on ENABLE pin (active LOW) instead of SLEEP uncomment next line
    // stepper.setEnableActiveState(LOW);
}

void loop() {

  MoverMotores(180,16);
    // energize coils - the motor will hold position
    // stepper.enable();
  
    /*
     * Moving motor one full revolution using the degree notation
     */
    //stepper.rotate(-360);
    //stepper.move(MOTOR_STEPS*MICROSTEPS);
    //stepper.move(2048);
    /*
     * Moving motor to original position using steps
     */
    //delay(1000);
    //stepper.rotate(360);
    //stepper.move(-MOTOR_STEPS*MICROSTEPS);
    //stepper.move(-2048);
    // pause and allow the motor to be moved by hand
    // stepper.disable();

    //delay(5000);
}
void MoverMotores(int Grados, int Multiplicador){
      stepper.rotate(-Grados*Multiplicador);
      delay(1000);
      stepper.rotate(Grados*Multiplicador);
      delay(5000);
}
