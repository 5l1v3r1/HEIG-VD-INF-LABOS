#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "KorradiGottburgLabo7.h"

using namespace std;

int get_input(string MESSAGE, int MAX, int MIN = 1) {
   int value = 0;
   
   while (cin.fail() || value > MAX || value < MIN) {
      cout << MESSAGE;
      cin >> value;
      if(!value) {
	return value;
      }
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
   }
   
   return value;
}

int main() {
  const string MESSAGE_CHOICE = "Choix : ";
  const string MESSAGE_MENU_1 = "Veuillez entrer un nombre entier : ";
  const string MESSAGE_MENU_2 = "Veuillez entrer le nombre de ligne du losange [1 - 10] : ";
  const string MESSAGE_MENU_4 = "Veuillez entrer un nombre entier positif : ";
  const string MESSAGE_EXIT = "Aurevoir .";
  const short MAX_CHOICE = 5;
  const short MAX_DIAMOND = 10;
  
  unsigned int call_count = 0;
  unsigned int choice = 1;
  int value;
  
  while(choice)
  {
    choice = get_input(MESSAGE_CHOICE, MAX_CHOICE);
    
    switch (choice)
    {
      case 0:
	cout << MESSAGE_EXIT << endl;
	return 0;
      break;
      
      case 1:
	value = get_input(MESSAGE_MENU_1, numeric_limits<int>::max(), numeric_limits<int>::min());
	exercice1(value);
      break;
	  
      case 2:
	value = get_input(MESSAGE_MENU_2, MAX_DIAMOND);
	exercice2(value);
      break;
	  
      case 3:
	afficher(call_count);
      break;
	  
      case 4:
	exercice4();
      break;
	  
      case 5:
	exercice5();
      break;
    }
  }
  
  return 0;
}

void exercice1(int value) {
  bool is_perfect_square = false;
  int perfect_square = 1;
  int odd = 1;
  
  while (value >= perfect_square) {
    perfect_square += (odd += 2);
    if (value == perfect_square) {
      is_perfect_square = true;
    }
    cout << endl << perfect_square << endl;
  }
  cout << endl << value << (is_perfect_square == true ? " est" : " n'est pas") << " un carre parfait." << endl;
  
  return;
}

void exercice2(int value)
{
  const int MULTIPLICATOR = 2;
  const int WIDTH = MULTIPLICATOR * value;
  const char STAR = '*';
  int lines = WIDTH;
  
  for(int i = 0; i < value; i++)
  {
      cout << setw(WIDTH);
      for(int j = 0; j <= i; j++)
      {
	cout << STAR;
      }
      cout << endl;
      value--;
  }
  
  return;
}

void exercice4()
{
}

void exercice5()
{
}

void afficher(unsigned int &count)
{
  count = (++count <= numeric_limits<long long>::max() ? count : 0);
  cout << "Appel numero " << count << endl;
  
  return;
}

void displayDiamond(int nombre)
{
}

void displayFibonacci(int nombre)
{
}
