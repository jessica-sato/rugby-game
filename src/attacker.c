// Standard headers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "attacker.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t execute_attacker_strategy(
    position_t attacker_position, Spy defender_spy) {
  // TODO: unused parameters, remove these lines later
  UNUSED(defender_spy);
  
  srand(time(NULL));
  
  int ran = abs(rand() * (attacker_position.i + attacker_position.j)) ;
  int dir;
  
  if (attacker_position.j == 1){
    dir = ran%9;
  } 
  else{
    dir = ran%12;
  }

  direction_t direction_with_weigh_attacker[12] = {
    DIR_DOWN_RIGHT, //weigh 2                       
    DIR_UP_RIGHT,   //weigh 2                 
    DIR_RIGHT,      //weigh 3                     
    DIR_UP,
    DIR_DOWN,       
    DIR_DOWN_LEFT,  
    DIR_LEFT,       
    DIR_UP_LEFT,

    DIR_DOWN_RIGHT,
    DIR_UP_RIGHT,
    DIR_RIGHT,
    DIR_RIGHT};
               
  return direction_with_weigh_attacker[dir]; 
}

/*----------------------------------------------------------------------------*/
