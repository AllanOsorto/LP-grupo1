/*
 * TarjetaArduino.c
 *
 *  Created on: 7 jul. 2021
 *      Author: sayrasugelymoralesdiaz
 */


#include <stdio.h>
int main (){
	setup ();
	loop();
	Nivel_Agua();
}

int valorAlto;
int valorBajo;
int valorseguridad;
#define RGB_GREEN 3
#define RGB_BLUE 5
#define RGB_RED 6
#define espera 300
int OUTPUT;
int HIGH;
int LOW;
int ledPin = 13; 	// Pin de salida para el LED
int inPin = 2; // Pin de entrada (donde está conectado el interruptor)


void setup (){// Sistema RGB para la iluminacion de la fuente
	 pinMode (RGB_RED, OUTPUT);
	 pinMode (RGB_GREEN, OUTPUT);
	 pinMode (RGB_BLUE, OUTPUT);

	 }
void loop() {

digitalWrite(RGB_GREEN, LOW);
digitalWrite(RGB_BLUE, LOW);
digitalWrite(RGB_RED, LOW);

digitalWrite(RGB_GREEN, LOW);
digitalWrite(RGB_BLUE, HIGH);
digitalWrite(RGB_RED, LOW);
delay (espera);
digitalWrite(RGB_GREEN, LOW);
digitalWrite(RGB_BLUE, LOW);
digitalWrite(RGB_RED, HIGH);
delay(espera);
}

void setup() {
   pinMode(ledPin, OUTPUT);
   pinMode(inPin, INPUT);
}




void Nivel_Agua(){// control del vaciado/llenado de la fuente
	 if(valorseguridad==1){

        Detener();
        vaciar ();

	 }
	 else{
		 if(valorAlto==1 && valorBajo==0){

		 }
		 else if(valorAlto==1 && valorBajo ==1){
			 llenar();
		 }
		 else if(valorAlto==0 && valorBajo ==0){
			 vaciar();
		 }
	 }

 }


