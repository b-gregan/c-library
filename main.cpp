
/*********************************
* AUTHOR   : Brenda Gregan
**********************************/

#include <iostream>
#include <iomanip>
#include "library.h"
using namespace std;

void printMenu();
// POSTCONDITION: Prints menu of actions user can choose from

int getCode();
// POSTCONDITION: Prompts user for book code

string getTitle();
// POSTCONDITION: Prompts user for book title

int getID();
// POSTCONDITION: prompts user for their user id

string getName();
// POSTCONDITION: Prompts user for their name

int main() 
{
  library lib;  // library object used to handle actions involving data from books.txt and person.txt
  int user;  // holds user input

  // continues to display menu and propmt user until invalid input or exit request is made
  do
  {
    printMenu();
    cout << "Select (1-6) : ";
    cin >> user;

    // calls library member function according to option chosen from user
    switch(user)
      {
        case 1: 
          lib.searchBook(getCode(), getTitle());
          break;
        case 2:
          lib.rent(getID(), getTitle());
          break;
        case 3:
          lib.returnBook(getID(), getCode());
          break;
        case 4:
          int id;
          id = getID();
          getName();
          lib.showInfo(id);
          break;
        case 5:
          lib.showBooks();
          break;
        case 6:
          std::cout << "Good bye!\n";
          break;
        default:
          // if invalid input is entered, program ends
          user = 6;
          cout << "Invalid entry, closing program...\n";
      }
  }while(user != 6);
}

/*
  printMenu
------------------------------------------------------
Post : 
  - prints menu of selections user can choose
*/
void printMenu()
{
  std::cout << 
    "\n--------------------------------------\n";
  std::cout << std::setw(20) << "Menu" <<
    "\n--------------------------------------\n";
  cout << "1. Search a book\n" 
    << "2. Rent a book\n"
    << "3. Return a book\n"
    << "4. Show my information\n"
    << "5. Show all books\n"
    << "6. Exit\n";   
}

/*
  getCode
------------------------------------------------------
Post : 
  - prompts user for book code and returns that code
*/
int getCode()
{
  int code;  // book code
  
  cout << "Enter book code : ";
  cin >> code;
  return code;
}

/*
  printMenu
------------------------------------------------------
Post : 
  - prompts user for book title and returns that code
*/
string getTitle()
{
  string title;  // book title

  cout << "Enter book title : ";
  cin >> title;
  return title;
}

/*
  getID
------------------------------------------------------
Post : 
  - prompts user for their id and returns that value
*/
int getID()
{
  int id;  // user id

  cout << "Enter your id : ";
  cin >> id;
  return id;
}

/*
  getName
------------------------------------------------------
Post : 
  - prompts user for their name and returns that value
*/
string getName()
{
  string name;  // name of user

  cout << "Enter your name: ";
  cin >> name;
  return name;
}