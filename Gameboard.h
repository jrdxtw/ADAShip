#pragma once
  //"Pragama once" is introduced to cause the current source file to be included only once in a single compilation.
#include <iostream>
  //Function defines the standard devices cin, cout, clog, ceer;
#include <stdlib.h> 
  //This function is used to set a width "setw" for the board dimensions 
#include <iomanip> 
  //This function is used to get and retrieve a width "getw" for the board dimensions
#include <fstream> 
  //The function "fstream" is used to read and write files
#include <vector> 
  //vectors automatically manage storage. In this istance i wouls manage multiple aspect such as the position of the boats that the player has placed
#include <sstream> 
  //string stream
#include <cctype> 
  //For to upper. "cctype" declares a set of functions to classify (and transform) individual characters. For example, isupper() checks whether a character is uppercase or not.
#include "Helpers.h"
  //importing a header file for "helpers.h"

using namespace std;

class Board {
  private:
  //A "private" class illistrates that only members of the same class are allowed to access
		//the singleton's constructor should always be private or protected to limit direct construction calls with the `new` operator.
    void load_data();
    void initialise_board();
    //Board initalisation 

  protected:
  //essentially, protected means that members of subclasses are also allowed
    int board[30][30];
    //Gives the abililty to set the dimensions of the board
    int board_size;
    //Make board size

    struct boat 
    {
      string name;
      int size;
      bool placed;
      int hits;
      bool sank;
    };
    vector <boat> boats;

  public:
  //A public class refers to public which means that everyone is allowed to access to the class

    Board();

    void print_ship_board();
    void print_target_board();

    vector<int> format_coordinate(string coordinates);
    void reset_board();
    bool valid_coordinate(vector<int> coordinate);
    int fire(vector<int> coordinate);
    bool is_valid_target(vector<int> _coordinate);
    int auto_fire();

    
};
