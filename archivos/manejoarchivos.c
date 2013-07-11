#INCLUDE <16f887.h>

#USE delay(clock=8000000)
#INCLUDE "timers.c"  //doble comillas porque esta en la carpeta del proyecto
#INCLUDE "bsp.c"

void main()
{  int x;
   bsp_init();
   timers_init();
   enable_interrupts(GLOBAL);
   bsp_init();
   timers_set_time(1,_100ms);
   
   while(TRUE)
   {
   
   if (timers_get_time(1)==0)
   {
    timers_set_time(1,_100ms);
    bsp_led_toggle(0);  
   }
   
  
   }

}
