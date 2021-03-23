#include "Headers/main.h"
//importing the following header file "main.h"
using namespace std;

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

  cout << "▄▀█ █▀▄ ▄▀█ █▀ █ █ █ █▀█" << endl;
  cout << "█▀█ █▄▀ █▀█ ▄█ █▀█ █ █▀▀" << endl;
  //Prints a graphic into menu system

  cout << "\n\n";
 
  cout << "Welcome to Adaships Battleship!" << endl;
  //Prints the following message within the menu

  while (menu_choice != 0) 
  {
    cout << "1. One player V computer game\n\nPlease select an option (or 0 to quit): ";
    //Prints the game mode 
    if( ! (cin >> menu_choice)) 
    { 
    //catching erroneous input
      cout << "Invalid input\n";
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
        cout << "\nInvalid Input, please try again...\n";
        //Printed the following message to indicate to try again
        break;
    }
  }
  cout << "\nGood bye\n";
}
