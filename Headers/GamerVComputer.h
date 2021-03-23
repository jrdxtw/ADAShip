#include <iostream>
  //Function defines the standard devices cin, cout, clog, ceer; 
#include <vector> 
  //vectors automatically manage storage. In this istance i wouls manage multiple aspect such as the position of the boats that the player has placed
#include <limits>
  // "Limits" provides information about the properties of arithmetic types (either integral or floating-point) in the specific platform for which the library compiles.
#include "Gameboard.h"
  //Function calls for header file "gameboard.h" to be integrated
#include "Boats.h"
  //Function calls for header file "boats.h" to be integrated
void playerVcomputer(Boats &_player, Boats &_comp);