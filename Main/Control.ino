void Guardar(){
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
      Serial.println( Posiciones [i] [1]);
    }
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
}
