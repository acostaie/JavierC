#include <12f510.h>
#include <stdio.h>
#fuses intrc
#use delay (clock=8000000)
#byte portB=0x06

void main()
{
set_tris_b(0x00);



   while(TRUE)
   {
      portb=0;
      delay_ms(200);
      portB=1;
   }

}
