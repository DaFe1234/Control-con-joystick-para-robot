// ****************************
//                            *
//          Motores           *
//                            *
// ****************************
// Para Base driver eje X STEP 5 y DIR 2 / Para Codo driver eje z STEP 7 y DIR 4 / Para Hombro eje y STEP 6 y DIR 3
#include <Arduino.h>
#include <EEPROM.h>
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
// CoolEn = A3
// Resume = A2
int Joystick [2] = {A0,A1};
int Joystick2 [2] = {A6,A7};

boolean Flag = 1;
boolean Flag2 = 0;
int BotonPosiciones = A2;
int InfrarojoPosiciones = A3;
int BotonGuardarEEPROM = 9;
int BotonMostrar = 10;
int BotonGuardar = 11;
int BotonReiniciar = 12;
int BotonLeerEEPROM = 13;
char Dato = 0;

int LecturaDeBotonPosiciones = 0;
int LecturaDeInfrarojoPosiciones = 0;
int LecturaDeJoystick [2];
int LecturaDeJoystick2[2];
int LecturaBotonGuardarEEPROM = 0;
int LecturaBotonMostrar = 0;
int LecturaBotonGuardar = 0;
int LecturaBotonReiniciar = 0;
int LecturaBotonLeerEEPROM = 0;


int Contador = 0;
int Posiciones [50] [2];
int Posiciones2 [50] [2];

struct ObjetoPosiciones{
  
  int contadorDeDatos = 0;
  int MatrizPosiciones [20] [2];
  int MatrizPosiciones2 [20] [2];
  
};

void setup() {
  // put your setup code here, to run once:
    stepper_x.begin(55, MICROSTEPS);
    stepper_y.begin(55, MICROSTEPS);
    stepper_z.begin(55, MICROSTEPS);

    Serial.begin(115200);
    pinMode(BotonGuardarEEPROM, INPUT);
    pinMode(BotonLeerEEPROM,  INPUT);
    pinMode(BotonGuardar,     INPUT);
    pinMode(InfrarojoPosiciones, INPUT);
    pinMode(BotonMostrar,   INPUT_PULLUP);
    pinMode(BotonReiniciar, INPUT_PULLUP);
    pinMode(BotonPosiciones, INPUT_PULLUP);
    Serial.println("Sus posiciones son");
    LecturaDeEEPROM();


}

void loop() {
    LeerJoysticks();
    Mostrar();
    Reiniciar();
    Guardar();
    GuadarEnEEPROM2();
    LecturaDeEEPROM2();
  //Reviso si hay algun dato en el serial
  if(Serial.available() > 0){
    Dato = Serial.read();
    Serial.println(Dato);
  }
  switch(Dato){
    case 'h':
      Home();
      break;
      
    case 'i':
      Home2();
      break;

    case 'c':
      Coindicion();
      break;

    case 'o':
      ActivarMotores(0);
      break;
  }
 

}
