//ingresa un dato con los microsw,el programa lee cuantos ceros estan encendidos.
#include <16f887.h>
#include <stdio.h>
#fuses INTRC_IO
#use delay (clock=4000000)
#include <lcd.c>
void init();
int16 lee_dato(void);
int procesa_dato(int x);
void despliega(int x);

void main()
{  int dato,dato_procesado;

   init();
   while(TRUE)
   {
   dato=lee_dato();
   dato_procesado=procesa_dato(dato);
   despliega(dato_procesado);
   delay_ms(100);
   }

}

int16 lee_dato(void)
   {
   
   int1 ent0,ent1,ent2,ent3,ent4,ent5,ent6,ent7;
   int8 valor; 
   ent0 = input(PIN_C0);
   ent1 = input(PIN_C1);
   ent2 = input(PIN_C2);
   ent3 = input(PIN_C3);
   ent4 = input(PIN_C4); 
   ent5 = input(PIN_C5);
   ent6 = input(PIN_E1);
   ent7 = input(PIN_E2);
        
   valor=ent0*1;
   valor+=(ent1*2);
   valor+=(ent2*4);
   valor+=(ent3*8);
   valor+=(ent4*16);
   valor+=(ent5*32);
   valor+=(ent6*64);
   valor+=(ent7*128);
   return valor;
   }


void init()
   {
      setup_comparator(NC_NC_NC_NC);
      set_tris_c(0b11111111);
      set_tris_e(0xFF);
      lcd_init();
   }
   
 
int procesa_dato(int x)
{
   int i,a;
   int contador = 0;
   int m = 0b00000001;
   
   /*int procesa_dato(int d)    // este algoritmo cuenta los ceros
   {
   int bits,j,b=0;
      for(j=0;j<8;j++)
      {
       bits=b & (1<<j);
       if(bits==0)  
       {
       b++;
       }
      }
      return d;
   }
   */
   for (i = 0; i < 8 ; i++) // este algoritmo cuenta los 1s y le resta 8 para saber cuantos ceros hay.
   {
      if ( x & m )
         {contador++;      
         }
          m = m << 1; 
   }
   
   a= contador-8; 
   return -a;
}

void despliega(int x)
{
   lcd_putc("\f");
   lcd_putc("El # de 0's");
   printf(lcd_putc,"es: %u",x);
}
