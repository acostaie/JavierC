//interrupcion timer0
#include <16f887.h>
#include <stdio.h>
#fuses INTRC_IO
#use delay(clock=8000000)
#BYTE puertoA=0x05
int i=0;

               //Tiene que estar separado de arriba
#int_timer0
void timer_isr(void)             //interrup_TMR0=4*(1/F.Oscilador)*(256-valorTMR0)*Preescalador
{                               // 100ms=4*(1/8000000)*(256-valor)*256
  i++;                             //valor=100/(4/8000000)*256)-256 valor=
                                    //puertoA =  puertoA ^  (1<<3);
  set_timer0(178);

}

void main()
{  
   puertoA=0;
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_256);
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);
   set_tris_a(0x00);  
   set_timer0(178); // se precarga el timer para que cuente menos
   setup_comparator(NC_NC_NC_NC);
  
  
   
   while(TRUE)  
    { 
   
    if (i==10)
   {
    i=0;
    puertoA =  puertoA ^  (1<<5);
   }
   
   }

}
