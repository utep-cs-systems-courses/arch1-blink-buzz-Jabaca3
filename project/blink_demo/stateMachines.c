#include <msp430.h>
#include "stateMachines.h"
#include "libTimer.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

char toggle_red()		/* always toggle! */
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
}

char toggle_green()	/* only toggle green if red is on!  */
{
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}


void state_advance()		/* alternate between toggling red & green */
{
  /*char static state = 0;  

  switch (state) {
  case 0: red_on=1; green_on=0;state++; break;
  case 1: red_on=0; green_on=1; state++; break;
  default: state =0;
  }

  led_changed = 1;
  led_update();
  */
}

void buzzer_state_advance(){
  if(switch_state_down_1){
    static char buzz_state= 0;
    switch(buzz_state){
    case 0: buzzer_set_period(3822); red_on=0; green_on=1; buzz_state++; break;
    case 1: buzzer_set_period(3214); red_on=0; green_on=1; buzz_state++; break;
    case 2: buzzer_set_period(2551); red_on=0; green_on=1; buzz_state=0; break;
    default: buzz_state =0;
    }
  }
  else if(switch_state_down_2){
    static char buzz_state= 0;
    switch(buzz_state){
    case 0: buzzer_set_period(3822); red_on=1; green_on=0; buzz_state++; break;
    case 1: buzzer_set_period(3214); red_on=1; green_on=0; buzz_state++; break;
    case 2: buzzer_set_period(2551); red_on=1; green_on=0; buzz_state=0; break;
    default: buzz_state =0;
    }
  }
  else if(switch_state_down_3){
    static char buzz_state= 0;
    switch(buzz_state){
    case 0: buzzer_set_period(3822); red_on=1; green_on=0; buzz_state++; break;
    case 1: buzzer_set_period(3214); red_on=0; green_on=1; buzz_state++; break;
    case 2: buzzer_set_period(2551); red_on=1; green_on=0; buzz_state=0; break;
    default: buzz_state =0;
    }
  }
  else if(switch_state_down_4){
    static char buzz_state= 0;
    switch(buzz_state){
    case 0: buzzer_set_period(3822); red_on=1; green_on=1; buzz_state++; break;
    case 1: buzzer_set_period(3214); red_on=1; green_on=1; buzz_state++; break;
    case 2: buzzer_set_period(2551); red_on=1; green_on=1; buzz_state =0;break;
    default: buzz_state =0;
    }
  } else {
      buzzer_set_period(0);
    }
  led_changed=1;
  led_update();
  }






