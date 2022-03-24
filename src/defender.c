// Standard headers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "defender.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t execute_defender_strategy(
    position_t defender_position, Spy attacker_spy) {
  // TODO: unused parameters, remove these lines later

  UNUSED(attacker_spy);
  
  srand(time(NULL));
  
  int ran = abs(rand() * (defender_position.i + defender_position.j)) ;
  int dir;
  
  if (defender_position.j == 8){
    dir = ran%7;
  } 
  else{
    dir = ran%10;
  }
  direction_t direction_with_weigh_defender[10] = {
    DIR_UP, // weigh 2
    DIR_DOWN, // weigh 2
    DIR_DOWN_LEFT,  
    DIR_LEFT,       
    DIR_UP_LEFT,
    DIR_UP_RIGHT,
    DIR_RIGHT,
    DIR_DOWN_RIGHT,

    DIR_UP,
    DIR_DOWN,};
    
  return direction_with_weigh_defender[dir]; 
}

/*----------------------------------------------------------------------------*/
