#include <msp430.h>
#include "stateMachines.h"
#include "libTimer.h"
#include "led.h"
#include "../button_demo/switches.h"

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
  char static state = 0;  

  switch (state) {
  case 0:
    red_on=1;
    green_on=0;
    state++;
    break;
  case 1:
    red_on=0;
    green_on=1;
    state++;
    break;
  default: state =0;
  }

  led_changed = 1;
  led_update();
}

void button_down(){
  if(switch_state_down){
    state_advance();
  }
}


