#include "book.h"
#include "person.h"
#include <fstream>

template <typename T>
struct node
{
  T *data;      // Holds data of node
  node<T> *next;// Points to next node
  node( T *data ) : data(data), next(0) {}
};

template <typename T>
struct leaf
{
  T *data;       // Holds data of leaf
  leaf<T> *right;// Points to right child
  leaf<T> *left; // Points to left child
  leaf(T *data) : data(data), right(NULL), left(NULL){}
};

class library
{
private:
  node<person> *list[2]; // Stores list of Teachers and Students
  leaf<book> *tree[3];  // Stores list of children, computer, and novel books

public:

  library();
// POSTCONDITION: Creates library object and fills 'list' and 'tree' with data from files 'books.txt' and 'person.txt'

  ~library();
// POSTCONDITION: Destroys library object and deletes dynamic memory

  void searchBook(int code, std::string t);
// POSTCONDITION: Prints information of given book if found, if not found prints statement that the book does not exist

  void rent(int id, std::string t);
// PRECONDITION: valid id and book title are given
// POSTCONDITION: person will now be renting given book

  void returnBook(int id, int code);
// PRECONDITION: valid id and book code are given
// POSTCONDITION: person will no longer be renting given book

  void showInfo(int id);
// PRECONDITION: valid id is given
// POSTCONDITION: all of the books given person is renting will be printed

  void showBooks();
// POSTCONDITION: all of the books, and their information, stored in the "library" are printed

private:

  void getTree();
// POSTCONDITION: 'tree' is filled with data from books.txt file

  void getBook(int c, std::ifstream &in, book *&temp);
// POSTCONDITION: book pointer is filled with the according data from 'in' which is determined by its code 'c'

  void buildTree(leaf<book> *&root, book *val);
// POSTCONDITION: 'val' is input in its appropriate position in the passed tree

  void inputLeaf(leaf<book> *parent, char side, book *val);
// POSTCONDITION: 'val' is input as either the right/left child of parent if it is not null but if parent is null then parent points to val

  void getList();
// POSTCONDITION: 'list' is filled with data from person.txt file

  void inputNode(node<person> *&head, person *val);
// POSTCONDITION: 'val' is input into the passed linked list

  void printTree(leaf<book> *root);
// POSTCONDITION: contents of passed tree is printed

  void deleteTree(leaf<book> *&root);
// POSTCONDITION: dynamic memory in passed tree is deleted

  void deleteList(node<person> *&head);
// POSTCONDITION: dynamic memory in linked list is deleted

  book* findBookC(int code, std::string t);
// POSTCONDITION: 'tree' is searched to find passed book, if it is found a pointer of that book is returned, if not then pointer with code of -1 is returned

  book* searchC(leaf<book> *root, int code);
// POSTCONDITION: passed tree is searched to find passed code, if book is found then pointer of that book is returned, if not then pointer with code of -1 is returned

  book* searchT(leaf<book> *root, std::string t);
// POSTCONDITION: passed tree is searched to find passed book by its title, if book is found then pointer of that book is returned, if not then pointer with code of -1 is returned

  person* findPerson(node<person> *head, int id);
// POSTCONDITION: passed list is searched to find person, if person is found, then pointer of that person is returned, if not then pointer with id of -1 is returned
};