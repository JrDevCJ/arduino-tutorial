#include <Arduino.h>
#include <TM1637Display.h>

// Conexão dos pinos
#define CLK 6 //Pino utilizado pelo (CLK)
#define DIO 7 //Pino utilizado pelo (DIO)

//Passa a informação dos pinos como parâmetros da função da biblioteca (TM1637Display)
TM1637Display display(CLK, DIO); 

// Tempo (em milisegundos) entre os testes 
#define TEMP_DELAY   500

int minutos = 0;
int segundos = 0;
int temp = 0;

void setup(){
  display.setBrightness(0x0f); // Define a intensidade luminosa dos segmentos do display
}

void loop(){

    if(segundos == 60){
      temp += 100;
      minutos = temp;   
      segundos = 0;
    }
    
    display.showNumberDecEx(minutos, 0b11100000, true, 4, 0); // Imprime o tempo de exibição com dois pontos 
    delay(100);
    display.showNumberDec(minutos, true); // Imprime o tempo de exibição sem dois pontos 
    segundos++; //Incrementa a variável em +1 
    minutos++; //Incrementa a variável em +1 
    
    delay(TEMP_DELAY);

}
