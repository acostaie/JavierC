//interrupcion timer0
#include <16f887.h>
#include <stdio.h>
#fuses INTRC_IO
#use delay(clock=8000000)
#BYTE puertoA=0x05
int  timers[10]={0,0,0,0,0,0,0,0,0,0};
int n_timers=10;
void proceso1();
void proceso2();
void proceso3();

               //Tiene que estar separado de arriba
#int_timer0
void timer_isr(void)             //interrup_TMR0=4*(1/F.Oscilador)*(256-valorTMR0)*Preescalador
{                               // 100ms=4*(1/8000000)*(256-valor)*256
                                    //puertoA =  puertoA ^  (1<<3);
  set_timer0(178);                 //desjepe TMR0=tiempo(
  while(n_timers)
  {
     n_timers--;
     if(timers[n_timers]!=0)
     {
     timers[n_timers]--;
     }
  }
n_timers=10;
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
   timers[2]=10;
   timers[1]=20;
   timers[3]=30;
   
   while(TRUE)  
    { 
   proceso1();
   proceso2();
   proceso3();
    }

}

void proceso1(void)
{

    if (timers[2]==0)
   {
    puertoA =  puertoA ^  (1<<5);
    timers[2] = 10;
   }
}

void proceso2(void)
{
 if (timers[1]==0)
   {
    puertoA =  puertoA ^  (1<<4);
    timers[1] = 20;
   }
}

void proceso3(void)
{
 if (timers[3] == 0)
   {
    puertoA =  puertoA ^  (1<<3);
    timers[3] = 30;
   }
}
