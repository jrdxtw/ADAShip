#include "GamerVComputer.h"
//Function calls for header file within a folder "header" for file "helpers.h"

int player_turn_menu() 
{
  int menu_choice;
  cout << "\n\n It is you turn, what would you like to do?\n1. Fire a missile\n2. Auto fire\nPlease select and option (or 0 to quit): ";
  //Prints following message to indicate to user that its your turn to attack thier opponenet
  if( ! (cin >> menu_choice))
   { 
  //catching erroneous input
    std::cout << "\n This is an Invalid input! \n" << endl;
    cin.clear(); 
  //clearing the error from cin stream
    cin.ignore(10000, '\n');
    menu_choice = player_turn_menu();
  }
  else 
  {
    cin.ignore(10000, '\n');
  }
  return menu_choice;
}

int player1_turn(Boats &player1, Boats &enemy)
 {
  bool valid_coordinate = false, returnCode, valid_menu_choice = true;
  string coordinate_str;
  vector<int> coordinate;
  int boat_hit, won = 0; 
  // (1) = won the game, (-1) = quit, (0) = not won

  std::cout << "\n Your battleship board:\n" << endl;
  player1.print_ship_board();
  //Prints your board and the ships that are placed on them

  std::cout << "\n Your player target board:\n" << endl;
  enemy.print_target_board();
  //Prints your targetboard so you are able to view it

  do {
  //The do/while loop is a variant of the while loop. This loop will execute the code block once, before checking if the condition is true, then it will repeat the loop as long as the condition is true.  
    switch (player_turn_menu())
    {
      case 0:
        return -1;
      case 1:
        valid_menu_choice = true;
        while (valid_coordinate == false)
         {
          std::cout << "\n\n Enter your coordinates to fire at opponenet! : " << endl;
          //Prints message to indicate to user to enter coordinates to complete attack
          getline(cin, coordinate_str);
          try 
          {
            coordinate = enemy.format_coordinate(coordinate_str);
          } catch(int error)
           {
            std::cout << "\n Invalid coordinate: format needs to be LetterNumber, for example:E4 \n" << endl;
            //Prints message to inform user that the format is wrong and that they are required to use the following method of a LetterNumber sequence in order to attack.
            continue;
          }
          returnCode = enemy.valid_coordinate(coordinate);
          if (returnCode == false) 
          {
            std::cout << "\n Invalid coordinate position , board range out of bound! \n" << endl;
            //Prints message to inform user that the attack set by them is out of range and to try again.
            continue;
          }
          valid_coordinate = true;
        }
        boat_hit = enemy.fire(coordinate);
        break;
      case 2:
        valid_menu_choice = true;
        boat_hit = enemy.auto_fire();
        break;
      default:
        std::cout << "\n Thats an invalid option \n" << endl;
        //Prints message to user that its an valid option
        valid_menu_choice = false;
        break;
    }
  } while (!valid_menu_choice);

  cout << "\n Your target board:\n";
  enemy.print_target_board();

if (boat_hit > -1)
 {
    if(enemy.boat_sank(boat_hit))
    {
      std::cout << "The boat has been sank! \n" << endl;
      //Informing the player that the opponenet's boat has sunk
      if(enemy.all_boats_sank()) 
      {
        std::cout << "All boats have sank! \n" << endl;
        won = 1;
        //Informing the player that all boats have sunk
      }
    }
  }
  
  if (won != 1) 
  {
    std::cout << "\n Press enter to complete your turn!" << endl;
    char temp = cin.get();
    cin.clear();
  }
  
  return won;
}

bool comp_turn(Boats &enemy, Boats &comp) 
{
  int boat_hit, won = 0;

  std::cout << "\n The computers ship board: \n" << endl;
  comp.print_ship_board();
  
  std::cout << "\n The computers target board: \n" << endl;
  enemy.print_target_board();

  boat_hit = enemy.auto_fire();
  std::cout << "\n The computers target board: \n" << endl;
  enemy.print_target_board();
  
  if (boat_hit > -1) 
  {
    if(enemy.boat_sank(boat_hit))
    {
      std::cout << "The boat has been sank! \n" << endl;
      if(enemy.all_boats_sank()) 
      {
        std::cout << "All boats have sank! \n" << endl;
        won = 1;
      }
    }
  }
  
  std::cout << "\n Press enter to complete and end the turn!" << endl;
  
  char temp = cin.get();
  cin.clear();
  return won;
}

void playerVcomputer(Boats &_player, Boats &_comp) 
{
  bool comp_won = false;
  int player_won = 0;

  while (player_won == 0 && comp_won == false) 
  {
    system("clear");
    std::cout << "\n IT'S YOUR TURN: \n" << endl;
    player_won = player1_turn(_player, _comp);
    //Prints that it is Player 1's turn
    if (player_won!=0) 
    {
      continue;
    }
    system("clear");
    std::cout << "\n IT'S THE COMPUTERS TURN:\n " << endl;
    comp_won = comp_turn(_player, _comp);
    //Prints that its the AI's turn 
  }

  if (player_won == 1) 
  {
    std::cout << "\n YOU WON! \n\n" << endl;
    //Prints a winning message
  }
  else if (player_won == -1) 
  {
    std::cout << "\n Quiting game... \n\n" << endl;
    //Prints that the game is in the process of stopping
  }
  else 
  {
    std::cout << "\n You lost!Better luck next time! :(\n\n" << endl;
    //Prints that the player has lost
  }

  std::cout << "\n Press enter to return to menu..." << endl;
  //Prints message to the player to enter to return to menu
  char temp = cin.get();
  cin.clear();
}
