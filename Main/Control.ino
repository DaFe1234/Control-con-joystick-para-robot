void Guardar(){
    if(LecturaBotonGuardar == 1){
      if(Contador == 0){
         Serial.println("Guardando Posiciones"); 
      }  
      Posiciones [Contador] [0] = LecturaDeJoystick [0];
      Posiciones [Contador] [1] = LecturaDeJoystick [1];
      Posiciones2 [Contador] [0] = LecturaDeJoystick2 [0];
      Posiciones2 [Contador] [1] = LecturaDeJoystick2 [1];
      Serial.print( Posiciones [Contador] [0]);
      Serial.print("          ");
      Serial.print( Posiciones [Contador] [1]);
      Serial.print("          ");
      Serial.print(Posiciones2 [Contador] [0]);
      Serial.print("          ");
      Serial.println(Posiciones2 [Contador] [1]);
      delay(300);
      Contador++;
  }
}
void Reiniciar (){
    if(LecturaBotonReiniciar == 0){
     Contador = 0;
     Serial.println("Reiniciando Posiciones");
     delay(100);
  }
}

void Mostrar (){
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
      Serial.print( Posiciones [i] [1]);
      Serial.print("          ");
      Serial.print( Posiciones2 [i] [0]);
      Serial.print("          ");
      Serial.println( Posiciones2 [i] [1]);
    }
  }
}
void GuadarEnEEPROM2(){
    if(LecturaBotonGuardarEEPROM == 1){
    delay(300);
    GuardarEnEEPROM();
  }
}
void LecturaDeEEPROM2(){
  if(LecturaBotonLeerEEPROM == 1){
    delay(300);
    LecturaDeEEPROM();
  }
}
void LeerJoysticks(){
  LecturaBotones();
  LecturaDeJoystick [0] = analogRead(Joystick [0]);
  LecturaDeJoystick [1] = analogRead(Joystick [1]);
  LecturaDeJoystick2 [0] = analogRead(Joystick2 [0]);
  LecturaDeJoystick2 [1] = analogRead(Joystick2 [1]);
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
  Serial.println("Joystick1");
  for(int Filas = 0; Filas < Contador; Filas++){
    for(int Columnas = 0; Columnas < 2; Columnas++){
      MiObjeto.MatrizPosiciones [Filas][Columnas] =  Posiciones [Filas] [Columnas];
      Serial.print(MiObjeto.MatrizPosiciones [Filas][Columnas]);
      Serial.print("  ");
    }
    Serial.println("    ");
  }
  Serial.println("Joystick2");
  ObjetoPosiciones MiObjeto2;
  MiObjeto2.contadorDeDatos = Contador;
  for(int Filas = 0; Filas < Contador; Filas++){
    for(int Columnas = 0; Columnas < 2; Columnas++){
      MiObjeto2.MatrizPosiciones2 [Filas][Columnas] =  Posiciones2 [Filas] [Columnas];
      Serial.print(MiObjeto2.MatrizPosiciones2 [Filas][Columnas]);
      Serial.print("  ");
    }
  EEPROM.put(0,MiObjeto);
  EEPROM.put(sizeof(MiObjeto)+1,MiObjeto2);
  //Se pone "sizeof" para saber el tamaño que tiene el objeto
  Serial.println(sizeof(MiObjeto));
  //Serial.println();
 }
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
