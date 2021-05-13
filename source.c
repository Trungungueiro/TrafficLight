#include "header.h"


void init_semaforo(void)
{
  GREEN = 1;
  RED = 0; 
  YELLOW = 0;
	BOTAO = 0; 
}

void new_semaforo(void)
{
     GREEN = ~GREEN;
		 YELLOW = ~YELLOW;
		 delay(N);
		 YELLOW = ~YELLOW;
		 RED = ~RED 
}

void delay(unsigned char x)
{
  // mSec Delay 11.0592 Mhz
   unsigned int i;                                         
   while(count) {
       i = 115;
        while(i>0) i--;
          x--;
   } 
}

void conf_Timer0()
{
	TMOD=1; //timer 0 no modo 1 16 bits  
  TR0=0; //pausa timer para recarregar (Timer Stop)
  TH0=0x3C; //recarrega o timer com o valor
  TL0=0xAF; //15.535
  TR0=1; //ativa timer para contar (Timer RUN)
  EA=1; // activa todas interrupções
	ET0=1;  // activa interrupção do timer 0
	 
}

void isr_Timer0(void) interrupt 1{
  
	 if(contador<600) contador++;   
  
	
	if(GREEN == 1 && BOTAO == 1){ //  se o Botao for pressionado e o verde ligado 
		 delay(N);
     new_semaforo();
	   contador=0; //prepara p/recomeçar contagem de 1seg.
		  
		 }
			 
 else{ //se passou 50ms x600= 30 segundos
     new_semaforo();
	  contador=0; //prepara p/recomeçar contagem de 1seg. 
}  
}





void main()
{
	
  semaforo();
	conf_Timer0();
	delay(N);
	 
	while(1) {

		
}

}