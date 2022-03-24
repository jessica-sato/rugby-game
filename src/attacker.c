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
    
  int random_number = rand() * (attacker_position.i + attacker_position.j);
  int direction_index;
  
  static position_t previous_position = INVALID_POSITION;
  static int direction_count = 0;
  
  direction_t direction_with_weigh_attacker[12] = {
    DIR_DOWN_RIGHT,                        
    DIR_UP_RIGHT,                    
    DIR_RIGHT,                           
    DIR_UP,
    DIR_DOWN,       
    DIR_DOWN_LEFT,  
    DIR_LEFT,       
    DIR_UP_LEFT,};
  
  if(equal_positions(previous_position, attacker_position)){
    direction_index = direction_count;
    direction_count ++;
  }
  else{    
    direction_index = abs(random_number)%3; 
    direction_count = 0;
  }
  previous_position = attacker_position;
            
  return direction_with_weigh_attacker[direction_index]; 
}

/*----------------------------------------------------------------------------*/
