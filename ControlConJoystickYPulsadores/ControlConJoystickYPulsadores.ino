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
int LecturaBotonGuardarEEPROM = 0;
int BotonGuardarEEPROM = 9;
struct ObjetoPosiciones{
  
  int MatrizPosiciones [255] [2];
  
};
void setup() {
  Serial.begin(9600);
  pinMode(BotonGuardar,INPUT_PULLUP);
  pinMode(BotonMostrar,INPUT_PULLUP);
  pinMode(BotonReiniciar,INPUT);
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
  if(LecturaBotonGuardar == 0){
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
  GuardarEnEEPROM();

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
}
void GuardarEnEEPROM(){
  ObjetoPosiciones MiObjeto;
  for(int Filas = 0; Filas < 255; Filas++){
    for(int Columnas = 0; Columnas < 2; Columnas++){
      MiObjeto.MatrizPosiciones [Filas][Columnas] =  Posiciones [Filas] [Columnas];
      Serial.print(MiObjeto.MatrizPosiciones [Filas][Columnas]);
      Serial.print("  ");
    }
    Serial.println();
  }
}
