#pragma once
  //"Pragama once" is introduced to cause the current source file to be included only once in a single compilation.
#include <iostream>
  //Function defines the standard devices cin, cout, clog, ceer;
#include <stdlib.h> 
  //This function is used to set a width "setw" for boat sizes 
#include <iomanip> 
  //This function is used to get a width "getw" for boat sizes 
#include <fstream> 
  //The function "fstream" is used to read and write files
#include <vector> 
  //vectors automatically manage storage. In this instance it would manage multiple aspect such as the position of the boats that the player has placed it on the board.
#include <sstream> 
  //string stream
#include <cctype> 
  //for to upper. "cctype" declares a set of functions to classify (and transform) individual characters. For example, isupper() checks whether a character is uppercase or not.
#include <stdlib.h>     
  /* srand, rand */
#include <time.h>       
  //"time.h" header file contains definitions of functions to get and manipulate date and time information.

#include "Gameboard.h"
//importing the header file for "gameboard.h"

using namespace std;

class Boats: public Board
{
  private:
    void auto_place_ship(int ship_index);

  public:
    Boats();

    void print_boats();
    bool valid_boat_placement(vector<int> coordinate);
    int place_boat(vector<int> start_pos, char direction, string ship_name);
    bool all_ships_placed();
    
    int auto_place_all_ships();
    int auto_place_remaining_ships();
    bool boat_sank(int boat);
    bool all_boats_sank();
};

