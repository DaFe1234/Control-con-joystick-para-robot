#include <EEPROM.h>
int Joystick [2] = {A0,A1};
int LecturaDeJoystick [2];
int BotonGuardar = 11;
int LecturaBotonGuardar = 0;
int BotonMostrar = 10;
int LecturaBotonMostrar = 0;
int Posiciones [5] [2];
int Contador = 0;
int LecturaBotonReiniciar = 0;
int BotonReiniciar = 12;
int LecturaBotonGuardarEEPROM = 0;
int BotonGuardarEEPROM = 9;
struct ObjetoPosiciones{
  
  int contadorDeDatos = 0;
  int MatrizPosiciones [5] [2];
  
};
//Aqui voy a obtener mis posiciones de inicio
int LecturaBotonLeerEEPROM = 0;
int BotonLeerEEPROM = 13;
void setup() {
  Serial.begin(9600);
  pinMode(BotonGuardar,INPUT);
  pinMode(BotonMostrar,INPUT_PULLUP);
  pinMode(BotonReiniciar,INPUT_PULLUP);
  pinMode(BotonGuardarEEPROM, INPUT);
  pinMode(BotonLeerEEPROM,INPUT);
  Serial.println("Sus posiciones son");
  LecturaDeEEPROM();
}

void loop() {
  // put your main code here, to run repeatedly:
  LeerJoystick();
  delay(300);
  if(LecturaBotonReiniciar == 0){
     Contador = 0;
     Serial.println("Reiniciando Posiciones");
     delay(100);
  }
  if(LecturaBotonGuardar == 1){
      if(Contador == 0){
         Serial.println("Guardando Posiciones"); 
      }  
      Posiciones [Contador] [0] = LecturaDeJoystick [0];
      Posiciones [Contador] [1] = LecturaDeJoystick [1];
      Serial.print( Posiciones [Contador] [0]);
      Serial.print("          ");
      Serial.println( Posiciones [Contador] [1]);
      delay(300);
      Contador++;
  }
  if(LecturaBotonMostrar == 0){
    Serial.print("Mostrando posiciones");
    for(int i = 0; i<10; i++){
      Serial.print(".");
      delay(100);
    }
          Serial.println();
    for(int i = 0; i<Contador; i++){
      Serial.print( Posiciones [i] [0]);
      Serial.print("          ");
      Serial.println( Posiciones [i] [1]);
    }
  }
  if(LecturaBotonGuardarEEPROM == 1){
    delay(300);
    GuardarEnEEPROM();
  }
  if(LecturaBotonLeerEEPROM == 1){
    delay(300);
    LecturaDeEEPROM();
  }
}
void LeerJoystick(){
  LecturaBotones();
  LecturaDeJoystick [0] = analogRead(Joystick [0]);
  LecturaDeJoystick [1] = analogRead(Joystick [1]);
  /*Serial.print(LecturaDeJoystick [0]);
  Serial.print("    ");
  Serial.print(LecturaDeJoystick [1]);
  Serial.print("    ");
  Serial.print(LecturaBotonGuardar);
  Serial.println();*/
}
void LecturaBotones(){
  LecturaBotonMostrar = digitalRead(BotonMostrar);
  LecturaBotonGuardar = digitalRead(BotonGuardar);
  LecturaBotonReiniciar = digitalRead(BotonReiniciar);
  LecturaBotonGuardarEEPROM = digitalRead(BotonGuardarEEPROM);
  LecturaBotonLeerEEPROM = digitalRead(BotonLeerEEPROM);
}
void GuardarEnEEPROM(){
  Serial.println("Guardando en EEPROM");
  ObjetoPosiciones MiObjeto;
  MiObjeto.contadorDeDatos = Contador;
  for(int Filas = 0; Filas < Contador; Filas++){
    for(int Columnas = 0; Columnas < 2; Columnas++){
      MiObjeto.MatrizPosiciones [Filas][Columnas] =  Posiciones [Filas] [Columnas];
      Serial.print(MiObjeto.MatrizPosiciones [Filas][Columnas]);
      Serial.print("  ");
    }
    Serial.println();
  }

  EEPROM.put(0,MiObjeto);
  Serial.println(sizeof(MiObjeto));
}
void LecturaDeEEPROM(){
  Serial.println("Obteniendo datos");
  ObjetoPosiciones MiObjetoResultado;
  EEPROM.get(0, MiObjetoResultado);
  Serial.println(MiObjetoResultado.contadorDeDatos);
  for(int Filas = 0; Filas < MiObjetoResultado.contadorDeDatos; Filas++){
    for(int Columnas = 0; Columnas < 2; Columnas++){
      Serial.print(MiObjetoResultado.MatrizPosiciones [Filas][Columnas]);
      Serial.print("  ");
    }
    Serial.println();
  }
  delay(3000);
}
