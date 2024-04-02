#include <iostream>
#include <fstream>

class book
{
private:
  int code;  // code of book
  std::string title;  // title of book
  int available;  // number of available copies
  int rented;  // number of rented copies

public:

  book();
// POSTCONDITION: Book object is created and intitalized to 'null' values

  book(int c, std::string t, int a, int r);
// POSTCONDITION: Book object has been created and initialized with given values

  void setCode(int c);
// POSTCONDITION: sets code of book to given value

  void setTitle(std::string t);
// POSTCONDITION: sets title of book to given value

  void setAvailable(int a);
// POSTCONDITION: sets available copies of book to given value

  void setRented(int r);
// POSTCONDITION: sets rented copies of book to given value

  int getCode();
// POSTCONDITION: returns book code

  std::string getTitle(int type);
// POSTCONDITION: returns title of book with underscores or without according to 'type'

  int getAvailable();
// POSTCONDITION: returns number of available copies

  int getRented();
// POSTCONDITION: returns num of rented copies

  virtual void special();
// POSTCONDITION: prints type of special property of book

  virtual void category();
// POSTCONDITION: prints category of book

  virtual void printSpecial(int type);
// POSTCONDITION: prints unique data of book
};

class ChildrenBook : public book
{
private:
  int age;  // recommended age for book

public:

  ChildrenBook() : book() {age = -1;}
// POSTCONDITION: calls default parent constructor and initializes age to -1

  ChildrenBook(int c, std::string t, int av, int r, int a) : book(c, t, av, r){age = a;}
// POSTCONDITION: calls non-default parent constructor and set age to passed value

  void special();
// POSTCONDITION: prints type of special property for book

  void category();
// POSTCONDITION: prints category of book 

  void printSpecial(int type);
// POSTCONDITION: prints data of unique data
};

class ComputerBook : public book
{
private:  
  std::string publisher;  // publisher of book

public:

  ComputerBook() : book() {publisher = "";}
// POSTCONDITION: calls default parent constructor and initializes publisher to empty string

  ComputerBook(int c, std::string t, int a, int r, std::string p) : book(c, t, a , r){publisher = p;}
// POSTCONDITION: calls non-default parent constructor and sets publisher to passed value

  void special();
// POSTCONDITION: prints type of special property

  void category();
// POSTCONDITION: prints category of book

  void printSpecial(int type);
// POSTCONDITION: prints unique data of book
};

class Novel : public book
{
private:  
  int publishDate; // publish date of book

public:

  Novel() : book(){publishDate = -1;}
// POSTCONDITION: calls default parent constructor and sets publish date to -1

  Novel(int c, std::string t, int a, int r, int p) : book(c, t, a , r){publishDate = p;}
// POSTCONDITION: calls non-default parent constructor and sets publish date to passed value

  void special();
// POSTCONDITION: prints type of special property

  void category();
// POSTCONDITION: prints category of book

  void printSpecial(int type);
// POSTCONDITION: prints unique data of book
};