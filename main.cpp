#include "main.h"
//importing the following header file "main.h"

int playerVcomp() 
{
  int set_up_return_code;
  Boats player;
  Boats comp;
  //Sets up to return results to user

  cin.ignore();
  set_up_comp(comp);
  set_up_return_code = set_up_player(player);

  if (set_up_return_code == 1) 
  {
    return 1;
  }

  playerVcomputer(player, comp);
  return 0;
}

//Initiasling menu system
int main() {
  int menu_choice = -1, return_code_1;

  std::cout << "▄▀█ █▀▄ ▄▀█ █▀ █ █ █ █▀█" << endl;
  std::cout << "█▀█ █▄▀ █▀█ ▄█ █▀█ █ █▀▀" << endl;
  //Prints a graphic into menu system

  std::cout << "\n\n";
 
  std::cout << "Welcome to ADASHIP Battleship!" << endl;
  //Prints the following message within the menu

  while (menu_choice != 0) 
  {
    std::cout << "1. One player V Computer game\n\n Please select 1 for following gamemode (or 0 to quit): " << endl;
    //Prints the game mode 
    if( ! (cin >> menu_choice)) 
    { 
    //catching erroneous input
      std::cout << " Coordinates input are not valid! \n" << endl;
      cin.clear();
    //clearing the error from cin stream
      cin.ignore(10000, '\n');
      menu_choice = -1;
      continue; 
    //The function then will allow the next iteration of the loop
    }

    switch (menu_choice)
     {
      case 0:
        break;

      case 1:
        return_code_1 = playerVcomp();
        if (return_code_1 == 1) 
        {
          menu_choice = 0;
        }
        break;
      
      default:
        std::cout << "\n Coordinates input is invalid, please try again...\n" << endl;
        //Printed the following message to indicate to try again
        break;
    }
  }
  std::cout << "\n Thanks for Playing! \n";
}
