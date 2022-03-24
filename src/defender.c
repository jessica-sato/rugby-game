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
  
  int random_number = rand() * (defender_position.i + defender_position.j);
  int direction_index;
  
  static position_t previous_position = INVALID_POSITION;
  static int direction_count = 0;
  
  direction_t direction_with_weigh_defender[11] = {
    DIR_UP, // weigh 2
    DIR_DOWN, // weigh 2
    DIR_DOWN_LEFT,  
    DIR_LEFT,       
    DIR_UP_LEFT,
    DIR_UP_RIGHT,
    DIR_RIGHT,
    DIR_DOWN_RIGHT,
    DIR_STAY,

    DIR_UP,
    DIR_DOWN};
    
  if(equal_positions(previous_position, defender_position)){
    direction_index = direction_count;
    direction_count ++;
  }
  else{    
    direction_index = abs(random_number)%11; 
    direction_count = 0;
  }
  
  previous_position = defender_position;
  
  if (direction_count >= 11) {
    direction_count = 0;
  }
  return direction_with_weigh_defender[direction_index]; 
}

/*----------------------------------------------------------------------------*/
