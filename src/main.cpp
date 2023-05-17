#include <Arduino.h>
#include <Servo.h>
#include <max6675.h>

//SENSOR DE TEMPERATURA 
int ktc50=9;
int ktcCS=11;
int ktcCLK=12;
MAX6675 KTC(ktc50,ktcCLK,ktcCS);
float temp_current;
float temp_ref= 300;
float umbral=50;
int greca=8;

int TRIG=10;// sensor hc-sr
int ECO=6;// sensor hc-sr
int LED=10;// sensor hc-sr

int boton;
bool door1=true;
bool door2=true;
bool door3=true;
bool flag= true;




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
  pinMode(TRIG,OUTPUT );
  pinMode(ECO,INPUT );
  pinMode(LED,OUTPUT );
  //sensor hc-sr04
  servomotor.attach(10, pulsemin, pulsemax); //verificar pin disponible para el servo
  servomotor.write(pos_inicial);
  pinMode(greca, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, INPUT);
  t_init = millis();
}
void calefaccion  (){
  temp_current =KTC.readCelsius();
  if (temp_current<(temp_ref-umbral))
  {
    digitalWrite(greca, HIGH);
    /* code */
  } else{
    digitalWrite(greca, LOW);

  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
}