// ****************************
//                            *
//          Motores           *
//                            *
// ****************************
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

// ****************************
//                            *
//          Joystick          *
//                            *
// ****************************

int Joystick [2] = {A0,A1};
int LecturaDeJoystick [2];
int BotonGuardar = 12;
int LecturaBotonGuardar = 0;
int BotonMostrar = 13;
int LecturaBotonMostrar = 0;
int Posiciones [255] [2];
int Contador = 0;
int LecturaBotonReiniciar = 0;
int BotonReiniciar = 11;

void setup() {
  // put your setup code here, to run once:
    stepper_x.begin(RPM, MICROSTEPS);
    stepper_y.begin(RPM, MICROSTEPS);
    stepper_z.begin(RPM, MICROSTEPS);

    Serial.begin(9600);
    pinMode(BotonGuardar,INPUT_PULLUP);
    pinMode(BotonMostrar,INPUT_PULLUP);
    pinMode(BotonReiniciar,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 // Motores
  ActivarMotores(1);
  MoverMotores(-100,3);
  delay(300);
  MoverMotores(100,3);
  ActivarMotores(0);
  delay (10000);
 // Joystick
    LeerJoystick();
    delay(300);
    LeerJoystick();
    Mostrar();
    Reiniciar();
    Guardar();
}