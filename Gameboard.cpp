#include "Gameboard.h"
//Function calls for header file within a folder "headers" for file "Gameboard.h"

void Board::load_data() 
{
  string type, data, str_board_size, boat_name, boat_size;
  int counter = 0;

  ifstream game_config("adaship_config.ini"); 
//This function initiatied the opening data file to read it for the "Gameboard.cpp"

  while (getline(getline(game_config, type, ':'), data))
  { 
//A while loop is used here to loop through each line of the file of the program 
    if (type == "Board") 
    {
      stringstream ss(data);
      getline(ss, str_board_size, 'x');
      board_size = stoi(str_board_size);
    }
    else if (type == "Boat") 
    {
      stringstream ssb(data);
      boats.push_back(boat());

      while (getline(getline(ssb, boat_name, ','), boat_size))
      {
        boats[counter] = {lowercase_word(boat_name), stoi(boat_size), false, 0, false};
        counter++;
      }
    }
  };
  game_config.close(); 
  //"config.close"is used to close the data file to save and store game memory
};

void Board::initialise_board() 
{
  for (int y=0; y<board_size; y++) 
  {
    for (int x=0; x<board_size; x++) 
    {
      board[x][y] = 0;
    }     
  }
};

Board::Board() 
{
  load_data();
  initialise_board();
};

void Board::print_ship_board() 
{
  int empty = 0;  // contains water
  int counter = 0;
  char boat_initial;
  string boat_name;

  for(int a = 0; a < board_size; a++) 
  { 
  //function introduced coordinates for number functionality
    if (a>=26 && a<52){
      std::cout << setw(3) << 'A' << (char)((a-26)+'A') << endl;
    }
    else if (a>=52 && a<78) {
      std::cout << setw(3) << 'B' << (char)((a-52)+'A') << endl;
    }
    else if (a>=78) {
      std::cout << setw(3) << 'C' << (char)((a-78)+'A') << endl;
    }
    else 
    {
      std::cout << setw(3) << " " << (char)(a +'A') << endl;
    }
  }
  std::cout << endl;

  for(int j = 0; j < board_size; j++)
   { 
  //Function for coordinates for letter position and functionality 
    if(j >= 9)
    {
      std::cout << j+1 << endl;
    }
    else
    {
      std::cout << " " << j+1 << endl;
    }

    for(int i = 0; i < board_size ; i++) 
    {
    // cout << "in loop\n";

      if(board[i][counter] == empty) 
      {
        std::cout << setw(4) << " |" ;
      }
      else {
        boat_name = boats[(board[i][counter])-1].name;
        boat_initial = toupper(boat_name[0]);

        std::cout << setw(2) << boat_initial << setw(2) << "|";
      }
    }
    std::cout << "\n" << endl;
    counter ++;
  }
  std::cout << "\n" << endl;
};

void Board::print_target_board() 
{
  const int empty    = 0;  
  // contains water
  const int miss     = -1;  
  // shot into ocean
  const int hit      = -2;  
  // shot and hit

  int counter = 0;

  for(int a = 0; a < board_size; a++)
   { 
  //Function for coordinates for numbers functionality
    if (a>=26 && a<52)
    {
      std::cout << setw(3) << 'A' << (char)((a-26)+'A') << endl;
      //Prints the set width for specific characters
    }
    else if (a>=52 && a<78) 
    {
      std::cout << setw(3) << 'B' << (char)((a-52)+'A')<< endl;
      //Prints the set width for specific characters
    }
    else if (a>=78) 
    {
      std::cout << setw(3) << 'C' << (char)((a-78)+'A') << endl;
      //Prints the set width for specific characters
    }
    else 
    {
      std::cout << setw(3) << " " << (char)(a +'A') << endl;
      //Prints the set width for specific characters
    }
  }
  std::cout << endl;

  for(int j = 0; j < board_size; j++)
   { 
    //Function for coordinates for letter functionality
    if(j >= 9)
    {
      std::cout << j+1 << endl;
    }
    else {
      std::cout << " " << j+1 << endl;
    }

    for(int i = 0; i < board_size ; i++) 
    {

      if(board[i][counter] == miss )
      {
        std::cout << setw(2) << "M" << setw(2) << "|" << endl;
        //Prints the set width for specific characters
      }
      else if(board[i][counter] == hit ) 
      {
        std::cout << setw(2) << "H" << setw(2) << "|"<< endl;
        //Prints the set width for specific characters
      }
      else 
      {
        std::cout << setw(4) << " |" << endl;
        //Prints the width of the Gameboard
      }
    }
    std::cout << "\n"<< endl;
    counter++;
  }
  std::cout << "\n"<< endl;
};

vector<int> Board::format_coordinate(string coordinates) 
{
  const string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  //Prints characters on the gameboard
  int x_value = 0, y_value = 0, y_start_pos;

  // find the position of the first alpha character in coordinates
  for (int i=0; i < coordinates.length(); i++) 
  {
    if (isdigit(coordinates[i])) 
    {
      y_start_pos = i;
      break;
    }
  }
  if (y_start_pos==0) throw 20;

  //The following function will calculate the coordinate of "X"
  int x_coordinates = 0;
  for (int x=0; x < y_start_pos; x++) 
  {
    x_coordinates = x_coordinates * 26 + (alpha.find(toupper(coordinates[x]))) + 1;
  }
  x_value = x_coordinates-1;

  //The following function will calculate the coordinate of "Y"
  string y_coordinates;
  for (int y=y_start_pos; y < coordinates.length(); y++)
  {
    y_coordinates += coordinates[y];
  }
  y_value = stoi(y_coordinates)-1;

  return {x_value, y_value};
};

void Board::reset_board() 
{
  initialise_board();
  for(int i=0; i < boats.size(); i++) 
  {
    boats[i].placed = false;
  };
};

bool Board::valid_coordinate(vector<int> coordinate) 
{
  if(coordinate[0] < board_size && coordinate[1] < board_size)
  {
    return true;
  }
  else 
  {
    return false;
  }
};

int Board::fire(vector<int> coordinate) 
{
  int boat_num = board[coordinate[0]][coordinate[1]];
  int return_num = 0;

  if (board[coordinate[0]][coordinate[1]] == 0) 
  {
    std::cout << "\n BATTLESHIP MISSED! \n" << endl;
    board[coordinate[0]][coordinate[1]] = -1;
  }
  else if (board[coordinate[0]][coordinate[1]] < 0) 
  {
    std::cout << "\n You have already fired there,Try another region \n" << endl;
  }
  else if (board[coordinate[0]][coordinate[1]] > 0)
  {
    std::cout <<"\n BATTLESHIP HIT! \n" << endl;
    board[coordinate[0]][coordinate[1]] = -2;
    boats[boat_num-1].hits ++;
    return_num = boat_num-1;
  }
  return return_num;
};

bool Board::is_valid_target(vector<int> _coordinate) 
{
  if (_coordinate[0] < board_size && _coordinate[1] < board_size) 
  { 
  //This function will indicate if position is within board
    if (board[_coordinate[0]][_coordinate[1]] >= 0) 
    { 
  //The function will indicate if the  position hasn't already been hit yet
      return true;
    }
  }
  return false;
}


int Board::auto_fire() 
{
  vector<int> coordinates {0, 0};
  bool valid_target = false;

  srand (time(NULL));

  while(valid_target == false)
   {
    coordinates[0] = rand() % board_size; //(X)
    coordinates[1] = rand() % board_size; //(Y)

    if(is_valid_target(coordinates)) 
    {
      return fire(coordinates);
    }
    else {
      continue;
    }
  }
  return 0;
};
