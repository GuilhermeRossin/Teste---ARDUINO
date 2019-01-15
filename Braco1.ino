//////////////////////////// CONTROLE BRAÇO ROBOTICO 1 /////////////////
//Autor: Guilherme Rossin                               Data: 15/01/2019
////////////////////////////////////////////////////////////////////////

//Inclusao Bibliotecas
#include <VarSpeedServo.h>

// Variaveis Servo
VarSpeedServo servo_base;
VarSpeedServo servo_incli_1;
VarSpeedServo servo_incli_2;
VarSpeedServo servo_garra;

//variaveis Joystick 1
int pino_x1 = A2; // Eixo X do Joystick 1
int pino_y1 = A3; // Eixo Y do Joystick 1
int val_x1; //Armazena valor eixo X 1
int val_y1; //Armazena valor eixo Y 1

//variaveis Joystick 2
int pino_x2 = A4; // Eixo X do Joystick 2
int pino_y2 = A5; // Eixo Y do Joystick 2
int val_x2; //Armazena valor eixo X 2
int val_y2; //Armazena valor eixo Y 2

void setup() 
{
  servo_base.attach(2, 1, 180);
  servo_incli_1.attach(4, 1, 180);
  servo_incli_2.attach(6, 1, 180);
  servo_garra.attach(8, 1, 180);
}

void loop() 
{
  val_x1 = analogRead(pino_x1);
  val_x1 = map(val_x1, 0, 1023, 1, 180);
  servo_base.slowmove(val_x1,60);

  val_y1 = analogRead(pino_y1);
  val_y1 = map(val_y1, 0, 1023, 1, 180);
  servo_incli_1.slowmove(val_y1, 60);

  val_x2 = analogRead(pino_x2);
  val_x2 = map(val_x2, 0, 1023, 1, 180);
  servo_incli_2.slowmove(val_x2, 60);

  val_y2 = analogRead(pino_y2);
  val_y2 = map(val_y2, 0, 1023, 1, 180);
  servo_garra.slowmove(val_y2, 60);

  delay(30);
}
