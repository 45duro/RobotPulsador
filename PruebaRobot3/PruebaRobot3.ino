                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      /* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#define PAUSA 2000

Servo myservos [3] ;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

int Potenciometros [4] = {A0,A1,A2,A3};
int pinMotores [4] = {7, 5, 6, 8};

int LecturaPotenciometros [4], velocidad = 3;

int posiciones[125][4] = {
  {170, 170, 80, 0}, //inicio
  {120, 105, 90, 0}, //Puente
  //------------------------punto1-------------------- seleccionar contacto
  {120, 105, 90, 0},  //punto1
  {120, 150, 50, 0}, //levantar
  //------------------------punto2-------------------- Enviar mensaje
  {90, 120, 100, 0}, //Puente
  {90, 120, 100, 0},  //Puente 
  {90, 90, 100, 0}, //punto2
  {90, 130, 20, 0}, //levantar

  //------------------------punto3-------------------- pegar texto
  {123, 150, 15, 0}, //Puente
  {123, 65, 15, 0},  //Puente 
  {123, 65, 15, 0}, //punto3
  {123, 120, 17, 0}, //levanta
  
  //------------------------punto4-------------------- enviar
  {50, 120, 60, 0}, //Puente
  {50, 105, 60, 0},  //Puente 
  {50, 88, 60, 0}, //punto4
  {50, 120, 60, 0}, //levantar

  //------------------------punto5-------------------- Volver a contactos
  {170, 170, 70, 0}, //inicio
  {148, 80, 70, 0}, //Puente
  {148, 80, 70, 0},  //punto5
  {148, 120, 70, 0}, //levantar

  //-----------------------punto6----------------------Arrastrar e iniciar nuevamente
  {120, 120, 55, 0}, //Puente
  {120, 100, 55, 0},  //Puente 
  {120, 100, 55, 0}, //punto3
  {120, 100, 92, 0}, //levanta
  {120, 100, 92, 0}, //levanta
  {120, 130, 92, 0} //levanta
  };

/*
int posicionesOriginal[125][4] = {
  {180, 180, 80, 0}, //inicio
  {120, 105, 90, 0}, //Puente
  {120, 105, 90, 0},  //punto1
  {120, 150, 50, 0}, //levantar
  //------------------------punto2-------------------- seleccionar contacto
  {90, 120, 100, 0}, //Puente
  {90, 120, 100, 0},  //Puente 
  {90, 90, 100, 0}, //punto2
  {90, 130, 45, 0}, //levantar

  //------------------------punto3-------------------- Enviar mensaje
  {65, 110, 60, 0}, //Puente
  {65, 100, 75, 0},  //Puente 
  {65, 100, 75, 0}, //punto3
  {65, 130, 75, 0}, //levanta
  
  //------------------------punto4-------------------- Pegar texto
  {108, 120, 75, 0}, //Puente
  {108, 120, 60, 0},  //Puente 
  {108, 90, 60, 0}, //punto4
  {108, 120, 50, 0}, //levantar

  //------------------------punto5-------------------- Seleccionar pegar
  {50, 120, 45, 0}, //Puente
  {50, 105, 45, 0},  //Puente 
  {50, 88, 45, 0}, //punto5
  {50, 120, 45, 0}, //levantar

  //------------------------punto6-------------------- Volver a contactos
  {180, 180, 70, 0}, //inicio
  {150, 80, 70, 0}, //Puente
  {150, 80, 70, 0},  //punto1
  {150, 120, 70, 0} //levantar
  }; 
*/
int posiciones2[125][4] = {
  {120, 120, 63, 0}, //Puente
  {120, 100, 63, 0},  //Puente 
  {120, 100, 92, 0}, //punto3
  {120, 110, 92, 0}, //levanta
  {120, 130, 92, 0} //levanta
  };

int posicionesX[125][4] = {
  {170, 170, 50, 0},
  {136, 120, 90, 0},
  {114, 120, 89, 0},
  {90, 150, 70, 0}
  };
void pocicionar_en_inicio (){
  MovimientoServos (110,160, 15, 1);
  MovimientoServos (0,160, 15, 0);
  MovimientoServos (100,50, 15, 2);
}
                      
void setup() {
  Serial.begin(9600);
  
  myservos[2].attach(10, 550, 2400);
  myservos[1].attach(11, 550, 2400);  // attaches the servo on pin 9 to the servo object
  myservos[0].attach(12, 550, 2400);
  
  pocicionar_en_inicio ();
  
  for(int i = 0; i < 10; i++){
    elegirServo();
  }
      



  myservos[2].detach();
  myservos[1].detach();  // attaches the servo on pin 9 to the servo object
  myservos[0].detach();
}

void loop() {
 /*
 MovimientoServos(myservos[2].read(),30,0,2);
 delay(1000);
 MovimientoServos(myservos[2].read(),0,30,2);
 delay(1000);
 MovimientoServos(myservos[0].read(),180,15,0);
 delay(1000);
 MovimientoServos(myservos[0].read(),0,15,0);
 delay(1000);
 Serial.println(myservos[1].read());
 */
}

void elegirServo(){
  
  for(int fil = 0; fil < 26; fil++){
    switch(fil){
      case 8:
        delay(PAUSA);
        break;
      /*
      case 12:
        delay(1000);
        break;
      */
      default:
        for(int col = 0; col < 4; col++){
          MovimientoServos (myservos[col].read(), posiciones[fil][col], velocidad, col);
        }
        break;
    }
       
  }
}
void MovimientoServos (int A, int B, int Velocidad, int SelectorServo){
  //voy a decidir si va para arriba o para abajo
    if(A<B){
        for (pos = A; pos <= B; pos += 1) { // goes from 180 degrees to 0 degrees
          myservos[SelectorServo].write(pos);// tell servo to go to position in variable 'pos'
          delay(Velocidad);                       // waits 15ms for the servo to reach the position
          
        }
    }
    else{
        for (pos = A; pos >= B; pos -= 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          myservos[SelectorServo].write(pos);              // tell servo to go to position in variable 'pos'
          delay(Velocidad);                       // waits 15ms for the servo to reach the position
        }
  
    }
}
