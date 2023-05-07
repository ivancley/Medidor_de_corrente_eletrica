// Programa: Medidor de Corrente com envio de dados via POST
// Autor: Ivancley 

// Pendencia de bibliotecas
// EmonLib 
// https://github.com/openenergymonitor/EmonLib
#include "EmonLib.h" 

EnergyMonitor em1;

//Tensão da rede eletrica
int rede = 220;
 
//Pino do sensor SCT
int pino_sct = A1;

void setup() {
  Serial.begin(9600);
  //Pino, calibracao - Cur Const= Ratio/BurdenR. 2000/33 = 60
  em1.current(pino_sct, 60);
  double Irms = em1.calcIrms(1480);
  Serial.print("Corrente : ");
  Serial.print(Irms); // Irms
  Serial.println("Potencia");
  Serial.print(Irms*rede);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:

}
