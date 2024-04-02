#include <iostream>

class person
{
private:
  int id;   // unique identification number 
  std::string name;  // Name of person
  int count;  // Number of books person has rented

public:

  person();
// POSTCONDITION: Initializes person with id of -1, count of 0 and name of " "

  person(int i, std::string n);
// POSTCONDITION: Initializes id and name to passed values and number of books rented to zero

  void setID(int i);
// POSTCONDITION: sets id to passed value

  void setName(std::string n);
// POSTCONDITION: sets name to passed value

  virtual bool checkOut(int c);
// POSTCONDITION: returns false if person object is not a teacher or student

  virtual bool returnBook(int c);
// POSTCONDITION: returns false if person obj is not a teacher or student

  virtual const int* getBooks();
// POSTCONDITION: returns null dummy variable

  int getID();
// POSTCONDITION: returns id value

  std::string getName();
// POSTCONDITION: returns persons name

  int getCount();
// POSTCONDITION: returns number of books rented

protected:
  void rentBook();
// POSTCONDITION: increases count by one

  void returned();
// POSTCONDITION: decreases count by one
};

class Teacher : public person
{
private:
  int max = 3;  // Max num of books Teacher can rent
  int code[3];  // Codes of books Teacher is renting

public:

  Teacher() : person()
{
  for(int i = 0; i < max; i++)
    code[i] = 0;
}
// POSTCONDITION: calls default parent constructor and initializes code values to 0

  Teacher(int i, std::string n) : person(i, n)
{
  for(int i = 0; i < max; i++)
    code[i] = 0;
}
// POSTCONDITION: calls non-default parent constructor and initializes code values to 0

  bool checkOut(int c);
// POSTCONDITION: if Teacher has not reached limit of books rented, then passed num is added to code, count is increased and true is returned. Otherwise false is retruned

  bool returnBook(int c);
// POSTCONDITION: if 'c' is found in code then that spot in code is set to next element or zero, count is decreased, and true is returned. Otherwise, false is returned

  const int* getBooks();
// POSTCONDITION: returns array of rented book codes: 'code'
};

class Student : public person
{
private:
  int max = 2; // Max num of books, student can rent
  int code[2]; // codes of book, student is renting

public: 

  Student() : person()
{
  for(int i = 0; i < max; i++)
    code[i] = 0;
}
// POSTCONDITION: calls default parent constructor and initializes code values to 0

  Student(int i, std::string n) : person(i, n)
{
  for(int i = 0; i < max; i++)
    code[i] = 0;
}
// POSTCONDITION: calls non-default parent constructor and initializes code values to 0

  bool checkOut(int code);
// POSTCONDITION: if student has not reached limit of books rented, then 'c' is added to code, count is increased and true is returned. Otherwise false is retruned

  bool returnBook(int code);
// POSTCONDITION: if 'c' is found in code then that spot in code is set to next element or zero, count is decreased, and true is returned. Otherwise, false is returned

  const int* getBooks();
// POSTCONDITION: returns array of rented book codes: 'code'
};