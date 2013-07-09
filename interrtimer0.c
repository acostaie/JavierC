//interrupcion timer0
#include <16f887.h>
#use delay(clock=8000000)

#int_timer0
void timer_isr(void)
{

}
void main()
{
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_256);
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);
   
   set_timer0(127); // se precarga el timer para que cuente menos
   
   while(TRUE)
   {
     
   }

}
