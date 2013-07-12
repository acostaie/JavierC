#ifndef __BSP__
#define __BSP__

//una funcion que acepte una variable de 8 bits y que regrese el numero de bits encendidos
int8 bits_encendidos(int8 x)
{
   int i;
   int contador = 0;
   int m = 1;
   
   for (i = 0; i < 8 ; i++)
   {
      if ( x & m )
         {
           contador++;
         }
          m = m << 1; 
   }
   return contador;    
}          

//2.-una funcion que acepte una variable de 8 bits y que regrese los bits apagados(0)

int8 bits_apagados(int8 y)
{
   int j=0,b;
   int cont = 0;
   int n = 1;
 for (j = 0; j < 8 ; j++) // este algoritmo cuenta los 1s y le resta 8 para saber cuantos ceros hay.
   {
      if ( y & m )
         {cont++;      
         }
          n = n << 1; 
   }
   
   b= cont-8; 
   return -b;
}

/*3.-una funcion que cuente el numero de caracteres dentro de un arreglo de caracteres
   terminado en nulo, la funcion aceptara un puntero como parametro,y  regresara una    
   variable entera con el numero de caracteres.*/
   
 int8 cuenta_cadena(int8 *x)
 {
 
 
 }


#endif
