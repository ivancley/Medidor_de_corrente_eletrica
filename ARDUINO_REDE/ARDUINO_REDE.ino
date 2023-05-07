#include "etherShield.h"
#include "ETHER_28J60.h"
// PROGRAMA: ENVIO DE DADOS VIA POST 
// AUTOR: Ivancley Brito 

//Define o MAC da placa de rede
static uint8_t mac[6] = {0x54, 0x55, 0x58, 0x10, 0x00, 0x24};
//Define o endereco IP da sua placa
static uint8_t ip[4] = {192, 168, 0, 123};
static uint16_t port = 80; 
ETHER_28J60 e;
 
int pin = 1; // Pino analogico para ligacao do LM35
int tempc = 0; // Variavel que armazena a temperatura em Celsius
// Variáveis para temperatura máxima e mínima
int maxtemp = -100,mintemp = 100; 
int i;
 
void setup()
{ 
  //Inicializa a placa com as configuracoes fornecidas
  e.setup(mac, ip, port);
}
 
void loop()
{
  //Gera um valor 
  tempc = 10;
 
  if (e.serviceRequest())
  {
    e.print("<H1>MakerHero - Teste ENC28J60</H1><br/>");
    e.print("<b>Valor potenciometro porta analogica 5 : ");
    e.print(analogRead(A5));
    e.print("<br/><br/>");
    e.print("Valor temperatura : ");
    e.print(tempc);
    e.print("&deg<br/><br/>");
    e.print("&deg<b/>");
    e.respond();
  }
  delay(100);
}