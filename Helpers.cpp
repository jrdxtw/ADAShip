#include "Helpers.h"
  //Function calls for header file within a folder "headers" for file "helpers.h"
using namespace std;

string lowercase_word(string word)
{
  //cout << "inside lowercase_word\n";
  string lowercase_word;
  for (int i=0; i<word.length(); i++) 
  {
    lowercase_word += tolower(word[i]);
  }
  return lowercase_word;
  //retuns the value
};