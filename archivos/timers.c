
#ifndef __TIMERS__ //incluir siempre para evitar redefininciones.
#define __TIMERS__// el nombre __NOMBREDELHEADER__ es una convencion , usar siempre

#define N_TIMERS       10

#define _10ms          1
#define _20ms          2   
#define _30ms          3  
#define _40ms          4
#define _50ms          5
#define _60ms          6
#define _70ms          7
#define _80ms          8
#define _100ms         10
#define _500ms         50
#define _1s            100
#define _2s            200
#define _3s            300
#define _5s            500

int8 gtimers=N_TIMERS;
int8 atimer[N_TIMERS];

void timers_init(void)
{
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_256);
   enable_interrupts(INT_TIMER0);
   set_timer0(178);
}

void timers_set_time(int8 timer,int8 time)
{
   atimer[timer]=time;
}

int8 timers_get_time(int8 timer)
{
return atimer[timer];
}
  
  #int_timer0
  void timers_isr(void)
{
   set_timer0(178);
   while(gtimers)
   {
   gtimers--;
      if(atimer[gtimers]!=0)
      {
         atimer[gtimers]--; 
      }
   }
   gtimers=N_TIMERS;

}
#endif


