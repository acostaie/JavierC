#ifndef __BSP__
#define __BSP__
#INCLUDE <stdio.h>
#FUSES INTRC_IO
#byte puertoA=0x05
#include <lcd.c>
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)

   void bsp_init(void)
   {
      set_tris_c(0xFF);
      set_tris_e(0xFF);
      set_tris_a(0);
      output_a(0);
      SETUP_ADC_PORTS(sAN5);
      SET_ADC_CHANNEL(5);
      setup_adc(ADC_CLOCK_DIV_32);
      lcd_init();
      
   }

   void bsp_leds(int8 val)
   {
      output_a(val);
   }
   
   int8 bsp_lee_sw(void)
   {
      int var;
      var = input(PIN_C0);
      var += (input(PIN_C1)*2);
      var += (input(PIN_C2)*4);
      var += (input(PIN_C3)*8);
      var += (input(PIN_C4)*16);
      var += (input(PIN_C5)*32);
      var += (input(PIN_E1)*64);
      var += (input(PIN_E2)*128);
      return var;
   }

   void bsp_led_on(int8 led)
   {
   puertoA=puertoA | (1<<led);
   }
   
   void bsp_led_off(int8 led)
   {
   puertoA=puertoA & (~(1<<led));
   }
   
   void bsp_led_toggle(int8 led)
   {
   puertoA=puertoA ^ (1<<led);
   }
   
   bsp_lee_unsw(int8 sw)
   {  int8 valor;
      valor = bsp_lee_sw();
      return (valor & (1<<sw) != 0);
   }
   
   int8 bsp_lee_pot(void)
   {
   int8 x;
   
   x = read_adc();
   return x;
   }

#endif
