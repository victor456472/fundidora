#include <Arduino.h>
int TRIG=10;
int ECO=6;
int LED=10;
int boton;
bool door1=true;
bool door2=true;
bool door3=true;
bool flag= true;
float temp_current;
float temp_ref= 300;
float umbral=50;

float dist_pared = 15; //ojo definir en el experimento
int t1=20; // definir en el experimento
int t2=20; // definir en el experimento
int t3=20; // definir en el experimento

void setup() {
  pinMode(TRIG,OUTPUT );
  pinMode(ECO,INPUT );
  pinMode(LED,OUTPUT );
  //sensor hc-sr04
}

void loop() {
  // put your main code here, to run repeatedly:
}