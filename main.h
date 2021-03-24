#pragma once
  //"Pragama once" is introduced to cause the current source file to be included only once in a single compilation.
#include <iostream>
  //Function defines the standard devices cin, cout, clog, ceer; etc 
#include <stdlib.h> 
  //function is introduced for set width setw for "main.h"
#include <iomanip> 
  //function is introduced for get width getw for "main.h"
#include <fstream> 
  //The function "fstream" is used to read and write files
#include <vector> 
  //vectors automatically manage storage. In this istance i wouls manage multiple aspect such as the position of the boats that the player has placed
#include <sstream> 
  //string stream
#include <cctype> 
  //"cctype" declares a set of functions to classify (and transform) individual characters. For example, isupper() checks whether a character is uppercase or not.
#include "Gameboard.h"
  //importing the header file "board.h" for printing board dimension and creation
#include "Gamesetup.h"
  //importing the header file "setup.h" for initial set up
#include "GamerVComputer.h"
  //importing the header file "playerVcomputer for functionality