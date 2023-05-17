#include <Arduino.h>
#include <Servo.h>

int TRIG=10;
int ECO=6;
int LED=10;
float ventana; 

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

//counter mucrosegundos

unsigned long t_init_mcs;
unsigned long t_current_mcs;
unsigned long period_mcs = 1000;

void setup() {
  pinMode(TRIG,OUTPUT );
  pinMode(ECO,INPUT );
  pinMode(LED,OUTPUT );
  //sensor hc-sr04
  servomotor.attach(10, pulsemin, pulsemax); //verificar pin disponible para el servo
  servomotor.write(pos_inicial);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, INPUT);
  t_init = millis();
  //variable para lectura del sensor ultrasonico
  t_init_mcs = micros();
}

void leer_sensor_ultrasonico(){
  t_current_mcs=micros();
  digitalWrite(TRIG, HIGH);
  if((t_current_mcs - t_init_mcs) >= period_mcs){
    digitalWrite(TRIG, LOW);
    ventana = pulseIn(ECO, HIGH)/58.2;
    t_init_mcs=t_current_mcs;
  }
}

void loop() {
  leer_sensor_ultrasonico();
  // put your main code here, to run repeatedly:
}