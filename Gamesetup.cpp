#include "Gamesetup.h"
//Function calls for header file within a folder "headers" for file "gamesetup.h"

void place_a_ship(Boats &player) {
  string ship_entered, coordinate, lowercase_ship;
  vector<int> formatted_coordinate;
  int return_code;
  char ship_direction;

  std::cout << "\n Your ship board:\n" << endl;
  player.print_ship_board();
  //Function prints your board

  std::cout << "Your ships:\n" << endl;
  player.print_boats();
  //Function prints your ships on "Gameboard"

  std::cout << "\n Please enter ship type to contine: " << endl;
  getline(cin, ship_entered);
  //Function prints the option to enter your desired vehicle

  std::cout << "Enter coordinates for ship placement to start (e.g. F7): " << endl;
  getline(cin, coordinate);
  //Function prints message to suggest to the player to enter coordinates to start game

  formatted_coordinate = player.format_coordinate(coordinate);

  std::cout << "Is the ship vertical(V) or horizontal(H)?: " << endl;
  ship_direction = cin.get();
  //Function is returing question to player if the vehicle is vertical or horizontal on the Gameboard

  lowercase_ship = lowercase_word(ship_entered);
  cout << "\nPlacing ship...\n";
  
  return_code = player.place_boat(formatted_coordinate, ship_direction, lowercase_ship);
  
  if (return_code == 0){
    std::cout << "\n The " << ship_entered << " ship is placed!\n" << endl;
    player.print_ship_board();
    //Function notifies player that your desired ship is placed
  }
  else {
    std::cout << "\n invalid coordinates, vehicle has not been placed.\n Please try again \n" <<endl;
    //System notifices player that they need to try again placing thier ship 
  }

  if (player.all_ships_placed()) {
    std::cout << "\n all ships have been placed! \n" << endl;
    //System prints messages telling player that "all ships have been placed!"
  };
}

void place_remaining_ships(Boats &player)
{
  int return_code;
  return_code = player.auto_place_remaining_ships();
  if (return_code == 0) {
    std::cout << "\n All remaining ships are placed!\n" << endl;
    player.print_ship_board();
    //System prints messages telling player that "All remaining ships have been placed!
  }
  else {
    std::cout << "\n ERROR: All ships have already been placed.\n Please reset the board first.\n" << endl;
  }
}

void place_all_ships(Boats &player)
{
  int return_code;
  return_code = player.auto_place_all_ships();

  if (return_code == 0) 
  {
    std::cout << "\n All ships are placed!\n" << endl;
    player.print_ship_board();
  }
  else {
    std::cout << "\nERROR: Ships have already been placed!\nPlease reset the board first or choose 'Auto-place remaining ships'\n" << endl;
  }
}

void reset_board(Boats &player)
{
  char reset_confirm;
  std::cout << "\nAre you sure you want to reset the whole board?(Y/N)\n" << endl;

  if( ! (cin >> reset_confirm))
   { 
  //catching erroneous input
    std::cout << "Invalid input\n" << endl;
    cin.clear(); 
  //clearing the error from cin stream
    cin.ignore(10000, '\n');
  }
  cin.ignore();

  if (tolower(reset_confirm) == 'Y')
   {
    player.reset_board();
    std::cout << "Board reset \n" << endl;
  }
}

void set_up_comp(Boats &_comp) 
{
  system("clear");
  std::cout << "\n SETTING UP THE COMPUTERS BOARD:\n" << endl;
  _comp.auto_place_all_ships();

  std::cout << "\nThe computers ship board:\n" << endl;
  _comp.print_ship_board();

  std::cout << "The computers ships:\n" << endl;
  _comp.print_boats();

  std::cout << "\nPress enter to end computer setup..." << endl;
  char temp = cin.get();
  cin.clear();
}

int set_up_player(Boats &_player) 
{
  int menu_choice = -1;
  string are_your_sure;

  system("clear");
  std::cout << "\nSET UP YOUR BOARD:\n" << endl;

  while (menu_choice != 0) 
  {

  std::cout << "\nFirst you need to set up your board.\n" << endl;
  std::cout << "1. Place a ship\n2. Auto-place remaining ships\n3. Auto-place all ships\n4. Reset board\n5. Continue to game\nPlease select an option (or 0 to quit): " << endl;
  //System will provide player with the following options to continue and attack
  
  if( ! (cin >> menu_choice)) 
  { 
  //catching erroneous input
    std::cout << "Invalid input\n" << endl;
    cin.clear(); 
  //clearing the error from cin stream
    cin.ignore(10000, '\n');
    menu_choice = -1;
    continue; 
  //continuing to the next iteration of the loop
  }
  cin.ignore();

  switch (menu_choice) 
  {
    case 1:
    place_a_ship(_player);
    break;

    case 2:
    place_remaining_ships(_player);
    break;

    case 3:
    place_all_ships(_player);
    break;
      
    case 4:
    reset_board(_player);
    break;
    case 5:
    
    if (_player.all_ships_placed()) 
    {

    std::cout << "\n Please confirm current coordinate placement is correct?(Y/N): " << endl;
    getline(cin, are_your_sure);
    are_your_sure = lowercase_word(are_your_sure);

    if(are_your_sure == "Y" || are_your_sure == "Yes") 
    {
      std::cout << "\n Press enter to end your setup..." << endl;
      //System will indicate to plater to complete their go and initiate next turn for computer
      char temp = cin.get();
      cin.clear();

      return 0;
    }
    else 
      {
      std::cout << "\n Returning to Menu...\n" << endl;
      //System will print message to player notifying them that the system will return to menu
      break;
      }
    }
    else 
      {
      std::cout << "\n Please place all ships before continuing \n" << endl;
      //System will notify player to "Please place all ships before continuing"
      break;
      }
    default:
      std::cout << "\n Coordinate Input invald, please try again...\n" << endl;
      break;
    }
  }

  return 1;
}