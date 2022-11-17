#include <Arduino.h>
#include <TM1637Display.h>

#define UP 2 // Seta o (pino 2) do arduino para leitura do botão UP
#define DOWN 3 // Seta o (pino 3) do arduino para leitura do botão DOWN
 
const int CLK = 6; //Seta o (pino 6) do arduino para o (pino CLK) do display
const int DIO = 7; //Seta o (pino 7) do arduino para o (pino DIO) do display

const uint8_t blank[] = {0x00, 0x00, 0x00,0x00};

TM1637Display display(CLK, DIO); //Configura o display 

int num = 0;

void setup(){
    pinMode(UP, INPUT_PULLUP);
    pinMode(DOWN, INPUT_PULLUP);
    display.setBrightness(0x0f); //Seta o brilho máximo do display 
    display.setSegments(blank);//Limpa o display
}

void loop(){
  
   display.showNumberDec(num, true, 4, 0);
   delay(200); //espera 200 milisegundos
   
  // Se UP button pressionado acrescenta +1
  if( digitalRead(UP) ){ 
    num++;         
    if(num > 9999)
      num = 0;
  }

  // Se DOWN button pressionado decrementa -1
  if( digitalRead(DOWN) ){ 
    num--;       
    if(num < 0)
      num = 9999;
  }
 
}
