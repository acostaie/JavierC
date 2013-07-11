#ifndef __TIMERS__ //incluir siempre para evitar redefininciones.
#define __TIMERS__// el nombre __NOMBREDELHEADER__ es una convencion , usar siempre


   void timers_init(void);
   void timers_set_time(int8 timer,int8 time);
   void timers_get_time(int8 timer);
   
  
#endif
