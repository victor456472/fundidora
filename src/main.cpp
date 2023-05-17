#include <Arduino.h>
#include <Servo.h>

int boton;
bool door1=true;
bool door2=true;
bool door3=true;

float dist_pared = 15; //ojo definir en el experimento
int t1=20; // definir en el experimento
int t2=20; // definir en el experimento
int t3=20; // definir en el experimento

const int pos_inicial = 20; //definir en el experimento
const int pos_final = 20; //definir en el experimento
unsigned long t_current;
unsigned long t_init;

//servomotor

int pulsemin=650;
int pulsemax=3600;

int pos_inicial = 0; //definir en el experimento
int pos_final = 180; //definir en el experimento

Servo servomotor;

void setup() {
  servomotor.attach(10, pulsemin, pulsemax); //verificar pin disponible para el servo
  servomotor.write(pos_inicial);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, INPUT);
  t_init = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
}