#include "book.h"
#include <iomanip>
using namespace std;

/*
book class - book
------------------------------------------------------
Post : 
  - creates book object and initializes member variables to "null" values
*/
book :: book()
{
  code = -1;
  title = " ";
  available = 0;
  rented = 0;
}

/*
book class - book
  int c - code of book
  string n - name of book
  int a - available copies
  int r - rented copies
------------------------------------------------------
Post : 
  - creates book object and initializes member variables to passed values
*/
book :: book(int c, std::string n, int a, int r)
{
  code = c;
  title = n;
  available = a;
  rented = r;
}

/*
book class - setCode
  int c - book code
------------------------------------------------------
Post : 
  - sets code to passed value
*/
void book :: setCode(int c)
{
  code = c;
}

/*
book class - setTitle
  string t - book title
------------------------------------------------------
Post : 
  - sets title to passed value
*/
void book :: setTitle(std::string t)
{
  title = t;
}

/*
book class - setAvailable
  int a - avaialble copies of book
------------------------------------------------------
Post : 
  - sets available to passed value
*/
void book ::  setAvailable(int a)
{
  available = a;
}

/*
book class - setRented
  int r - rented copies
------------------------------------------------------
Post : 
  - sets rented to passed value
*/
void book ::  setRented(int r)
{
  rented = r;
}

/*
book class - getCode
------------------------------------------------------
Post : 
  - returns book code
*/
int book :: getCode()
{
  return code;
}

/*
book class - getTitle
  int type - indicates if title be with/without "_"
------------------------------------------------------
Post : 
  - if type is 1, then title is returned with underscores
  - if type is not equal to 1 then title is returned without underscores
*/
std::string book :: getTitle(int type)
{
  std::string temp = "";

  if(type == 1)
    return title;
  
  for(int i = 0; i < title.length(); i++)
    {
      if(title[i] != '_')
        temp += title[i];
      else
        temp += " ";
    }
  return temp;
}

/*
book class - getAvaialable
------------------------------------------------------
Post : 
  - returns available copes
*/
int book :: getAvailable()
{
  return available;
}

/*
book class - getRented
------------------------------------------------------
Post : 
  - returns num of rented copies
*/
int book :: getRented()
{
  return rented;
}

/*
book class - special
------------------------------------------------------
Post : 
  - prints type of special property
*/
void book:: special()
{
  std::cout << "none";
}

/*
book class - category
------------------------------------------------------
Post : 
  - prints type of book
*/
void book:: category()
{
  std::cout << "Book";
}

/*
book class - printSpecial
------------------------------------------------------
Post : 
  - prints special property
*/
void book :: printSpecial(int type)
{
  std::cout << "No special Property";
}

/*
ChildrenBook class - special
------------------------------------------------------
Post : 
  - prints type of special property
*/
void ChildrenBook:: special()
{
  std::cout << "age";
}

/*
ChildrenBook class - category
------------------------------------------------------
Post : 
  - prints type of book 
*/
void ChildrenBook:: category()
{
  std::cout << "Children Book";
}

/*
ChildrenBook class - printSpecial
  int type - indicates if formatting is wanted
------------------------------------------------------
Post : 
  - prints special property with formatting if type = 1
  - if not equal to one, no formatting
*/
void ChildrenBook :: printSpecial(int type)
{
  if(type == 1)
    std::cout << std::setw(5) << age;
  else
    std::cout << age;
}

/*
ComputerBook class - special
------------------------------------------------------
Post : 
  - prints type of special property
*/
void ComputerBook:: special()
{
  std::cout << "publisher";
}

/*
ComputerBook class - category
------------------------------------------------------
Post : 
  - prints type of book
*/
void ComputerBook:: category()
{
  std::cout << "Computer Book";
}

/*
ComputerBook class - getCode
  int type - indicates if formatting is wanted
------------------------------------------------------
Post : 
  - prints special property with no formatting if type = 1
  - prints with no formatting if not equal to one
*/
void ComputerBook :: printSpecial(int type)
{
  std::string temp = ""; // holds publisher name

  // gets publisher name without underscores
  for(int i = 0; i < publisher.length(); i++)
    {
      if(publisher[i] != '-')
        temp += publisher[i] ;
      else
        temp += " ";
    }
  if(type == 1)
    std::cout << std::setw(18) << temp;
  else
    std::cout << temp;
}

/*
Novel class - special
------------------------------------------------------
Post : 
  - prints type of special property
*/
void Novel:: special()
{
  std::cout << "publish date";
}

/*
Novel class - category
------------------------------------------------------
Post : 
  - prints type of book
*/
void Novel:: category()
{
  std::cout << "Computer Book";
}

/*
Novel class - printSpecial
  int type - indicates if formatting is wanted
------------------------------------------------------
Post : 
  - prints type of special property with formatting if type = 1
  - prints without formatting if type != 1
*/
void Novel :: printSpecial(int type)
{
  if(type == 1)
    std::cout << std::setw(8) << publishDate;
  else
    std::cout << publishDate;
}