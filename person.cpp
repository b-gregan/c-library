#include "person.h"

/*
person::person
------------------------------------------------------
  Creates and initializes person object to id of -1, name of " " and count of 0
*/
person :: person()
{
  id = -1;
  name = " ";
  count = 0;
}

/*
person::person
  int i    : id is set to this value
  string n : name is set to this value
------------------------------------------------------
Creates and initializes person object to passed values and count to 0
*/
person :: person(int i, std::string n)
{
  id = i;
  name = n;
  count = 0;
}

/*
person::setID 
  int i : id is set to this value
------------------------------------------------------
Post : 
- member variable id is set to passed value
*/
void person ::setID(int i)
{
  id = i;
}

/*
person::setName 
  string name : name is set to this value
------------------------------------------------------
Post : 
- member variable 'name' is set to passed value
*/
void person :: setName(std::string n)
{
  name = n;
}

/*
person::checkOut 
  int c : code of book to be rented
------------------------------------------------------
Post : 
- false is returnes as object must be "signed in" as either a Teacher or Student
*/
bool person :: checkOut(int c)
{
  std::cout << "Sign in as a teacher or student to rent a book\n";
  return false;
}

/*
person::return book 
  int c : book code to be returned
------------------------------------------------------
Post : 
- false is returned as object must be "signed in" as a teacher or student
*/
bool person:: returnBook(int c)
{
  std::cout << "Sign in as a teacher or student to return book\n";
  return false;
}

/*
person::getBooks 
------------------------------------------------------
Post : 
- returns null dummy variable 
*/
const int* person::getBooks()
{
  return new int[1];
}

/*
person::getID 
------------------------------------------------------
Post : 
- returns value of 'id'
*/
int person :: getID()
{
  return id;
}

/*
person::getNAme 
------------------------------------------------------
Post : 
- returns value of 'name'
*/
std::string person :: getName()
{
  return name;
}

/*
person::getCount 
------------------------------------------------------
Post : 
- returns value of 'count'
*/
int person :: getCount()
{
  return count;
}

/*
person::rentBook 
------------------------------------------------------
Post : 
- increases 'count' by one
*/
void person :: rentBook()
{
  count ++;
}

/*
person::returned 
------------------------------------------------------
Post : 
- decreases 'count' by one
*/
void person:: returned()
{
  count--;
}

/*
Teacher::checkOut 
------------------------------------------------------
Post : 
- if 'count' is less than 'max' then 'c' is input into code, count is increased ad true is returned
- if 'count' has reached 'max' then false is returned
*/
bool Teacher::checkOut(int c)
{
  if(getCount() == max)
    return false;
  code[getCount()] = c;
  rentBook();
  return false;
}

/*
Teacher::returnBook 
------------------------------------------------------
Post : 
- true is returned if 'c' is found in array 'code' and then 'c' is removed from array
- false is returned if 'c' is not found in 'code'
*/
bool Teacher::returnBook(int c)
{
  for(int i = 0; i < getCount(); i++)
    {
      if(code[i] == c)
      {
        if(i + 1 < getCount())
          code[i] = code[i+1];
        else
          code[i] = 0;
        return true;
      }
    }
  return false;
}

/*
Teacher::getBooks 
------------------------------------------------------
Post : 
- returns values in array 'code'
*/
const int* Teacher :: getBooks()
{
  return code;
}

/*
Student::checkOut 
------------------------------------------------------
Post : 
- true is returned if number of books rented is less than max, then 'c' is added to array of book codes and 'count' is increased
- false is returned if max number of books are alsready rented
*/
bool Student::checkOut(int c)
{
  if(getCount() == max)
    return false;
  code[getCount()] = c;
  rentBook();
  return true;
}

/*
Student::returnBook 
------------------------------------------------------
Post : 
- true is returned if 'c' is found in array 'code' and then 'c' is removed from array
- false is returned if 'c' is not found in 'code'
*/
bool Student::returnBook(int c)
{
  for(int i = 0; i < getCount(); i++)
    {
      if(code[i] == c)
      {
        if(i + 1 < getCount())
          code[i] = code[i+1];
        else
          code[i] = 0;
        return true;
      }
    }
  return false;
}

/*
Student::getBooks 
------------------------------------------------------
Post : 
- returns values in array 'code'
*/
const int* Student :: getBooks()
{
  return code;
}