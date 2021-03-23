#pragma once
  //"Pragama once" is introduced to cause the current source file to be included only once in a single compilation. 
#include <iostream>
//Function defines the standard devices cin, cout, clog, ceer; 
#include <stdlib.h>
  //for setw
#include <iomanip> 
  //for getw
#include <fstream> 
  //read and write files
#include <vector> 
  //vectors automatically manage storage. In this istance i wouls manage multiple aspect such as the position of the boats that the player has placed
#include <sstream> 
  //string stream
#include <cctype> 
  //for to upper





#include "Gameboard.h"
  //importing the header file for "gameboard.h"
#include "Boats.h"
  //importing the header file for "boats.h"
#include "Helpers.h"
  //importing the header file for "helpers.h"


int set_up_player(Boats &_player);
void set_up_comp(Boats &_comp);
void place_a_ship(Boats &player);
void place_remaining_ships(Boats &player);
void place_all_ships(Boats &player);
void reset_board(Boats &player);