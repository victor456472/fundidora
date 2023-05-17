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

float ventana; 

int boton;
bool door1=true;
bool door2=true;
bool door3=false;
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

//counter mucrosegundos

unsigned long t_init_mcs;
unsigned long t_current_mcs;
unsigned long period_mcs = 1000;

int solenoides = 7;

void setup() {
  pinMode(TRIG,OUTPUT );
  pinMode(ECO,INPUT );
  pinMode(LED,OUTPUT );
  //sensor hc-sr04
  servomotor.attach(10, pulsemin, pulsemax); //verificar pin disponible para el servo
  servomotor.write(pos_inicial);
  pinMode(greca, OUTPUT);
  pinMode(solenoides, OUTPUT);
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
  calefaccion ();
  leer_sensor_ultrasonico();
  if(ventana < dist_pared) {
    while(flag){
      boton = digitalRead(4);
      calefaccion();
      digitalWrite(solenoides, HIGH);
      t_current = millis();
      if (((t_current-t_init_mcs)>t1) && door1)
      {
        servomotor.write(pos_final);
        door1 = false;
        t_init=t_current;
      }
      if (((t_current-t_init)>t2) && door2)
      {
        servomotor.write(pos_inicial);
        door2=false;
        door3=true;
        t_init=t_current;
      }
      if(((t_current-t_init)>t3) && door3){
        digitalWrite(solenoides, LOW);
        door3 = false;
        t_init=t_current;
        flag = false;
      }
      if(boton == 1){
        flag = false;
      }
    }
  }
  flag = true;
  door1 = true;
  door2 = true;
  // put your main code here, to run repeatedly:
}