#pragma once
  //"Pragama once" is introduced to cause the current source file to be included only once in a single compilation.   
#include <iostream>
//Function defines the standard devices cin, cout, clog, ceer; 
#include <stdlib.h>
  //This function is used to set a width "setw" 
#include <iomanip> 
  //This function is used to get a width "getw"
#include <fstream> 
  //The function "fstream" is used to read and write files
#include <vector> 
  //vectors automatically manage storage. In this istance i wouls manage multiple aspect such as the position of the boats that the player has placed
#include <sstream> 
  //string stream
#include <cctype> 
  //for to upper. "cctype" declares a set of functions to classify (and transform) individual characters. For example, isupper() checks whether a character is uppercase or not.
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