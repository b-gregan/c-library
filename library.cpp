#include "library.h"
#include <iomanip>

/*
library class - library 
------------------------------------------------------
Post : 
- creates and initializes library object. 'list' and 'tree' are set to null and then filled with data from person.txt and books.txt
*/
library :: library()
{
  list[0] = NULL;
  list[1] = NULL;
  for(int i = 0; i < 3; i++)
    tree[i] = NULL;
  
  getTree();
  getList();
}

/*
library class - ~library 
------------------------------------------------------
Post : 
- dynamic memery from meber varaibles are deleted
*/
library::~library()
{
  deleteTree(tree[0]);
  deleteTree(tree[1]);
  deleteTree(tree[2]);
  deleteList(list[0]);
  deleteList(list[1]);
}

/*
library class - searchBook
  int code - code of book to be searched
  string t - title of book to be searched
------------------------------------------------------
Post : 
- if passed book is found, then its information is printed
- if information is not found, then error statement is printed: does not exist
*/
void library:: searchBook(int code, std::string t)
{
  // Searches for book in all three trees and inputs result in temp
  book *temp(findBookC(code, t));  

  // if book is not found
  if(temp->getCode() == -1)
    return;
  std::cout << "\n" << t << "(" << code << ") exists.\n";

  // book info is printed
  std::cout << "category : ";
  temp->category();     std:: cout << "\n";
  temp->special();      std::cout << " : ";
  temp->printSpecial(0); std::cout << "\n";
}

/*
library class - rent
  int id   - id of person to rent given book
  string t - title of book to be rented
------------------------------------------------------
Pre:
  - given person and book must exist
  - person can't be renting max amount of books
Post : 
  - if preconditions are met and person replies that they wish to rent book, then book code is added to their rentals, book data is updated and sucess message is printed
- if not then failure message is printed
*/
void library::rent(int id, std::string t)
{
  person *p;    // person to be renting book
  book *b;      // book to be rented
  bool rented;  // true if rent rent is sucessful
  char user;    // user input
  std::string message; // message to be printed

  // searches for person
  if(id < 101)
    p = findPerson(list[0], id);
  else
    p = findPerson(list[1], id);

  // searches for book
  b = searchT(tree[0], t);
  if(b->getCode() == -1)
  {
    b = searchT(tree[1], t);
    if(b->getCode() == -1)
      b = searchT(tree[2], t);
  }

  // if book or person is not found
  if(p->getID() == -1 || b->getCode() == -1)
  {
    std::cout << "\nInvaid input...\n";
    return;
  }

  std::cout << "\nYou are " << p->getName() << 
    ". You rented " << p->getCount() << " book(s)\n";
  std::cout << "Do you want to rent '"<< t <<"' (y/n)? ";
  std::cin >> user;

  if(user != 'y' && user != 'Y')
    return;

  // checks if desired book is available
  if(b->getAvailable() > 0)
  {
    rented = p->checkOut(b->getCode());
    // if person has not reached max amount of rentals
    if(rented)
    {
      message = "Rent Sucessful. Check your info!\n";
      b->setAvailable(b->getAvailable()-1);
      b->setRented(b->getRented()+1);
    }
    else
      message = "Rent unsucessful, you have checked out maximum number of books.\n";
  }
  else
    message = "Rent unsucessful, this book is unavailable\n";

  std::cout << message;
}

/*
library class - returnBook
  int id   - id of person whose given book will be returned
  int code - code of the book to be returned
------------------------------------------------------
Pre:
  - given person and book must exist
  - person can't be renting max amount of books
Post : 
  - if preconditions are met and person replies that they wish to rent book, then book code is added to their rentals, book data is updated and sucess message is printed
- if not then failure message is printed
*/
void library::returnBook(int id, int code)
{
  book *b;      // book to be returned
  person *p;    // person whose returning said book
  bool returned;// true if boor return is sucessful
  char user;    // input of the user

  // searches for person of given id
  if(id < 101)
    p = findPerson(list[0], id);
  else
    p = findPerson(list[1], id);

  // if person is not found
  if(p->getID() == -1)
  {
    std::cout << "Invalid user information...\n";
    return;
  }
  // searches for book of given code
  b = findBookC(code," ");
  // if given book is not found
  if(b->getCode() == -1)
    return;

  std::cout << "\nWould you like to return '" <<
    b->getTitle(0) << "' (y/n)? ";
  std::cin >> user;

  if(user != 'y' && user != 'Y')
    return;

  returned = p->returnBook(code);
  // if book was found in persons rentals
  if(returned)
  {
    std::cout << "Return sucessful. Check your info!\n";
    b->setAvailable(b->getAvailable()+1);
    b->setRented(b->getRented()-1);
  }
  else
    std::cout << "Return unsucessful, you are currently not renting this book\n";
}

/*
library class - showInfo
  int id   - id of person whose info is to be shown
------------------------------------------------------
Pre:
  - given person must exist
Post : 
  - if preconditions are met persons book rentals and the books info is shown
  - if not, then failure message is printed
*/
void library::showInfo(int id)
{
  person *p;    // person whose info is to be shown
  book *b;      // holds books person is renting
  const int *c; // list of books person is renting

  // searches for person
  if(id < 101)
    p = findPerson(list[0], id);
  else
    p = findPerson(list[1], id);

  // if person is not found
  if(p->getID() == -1)
  {
    std::cout << "\nInvalid user information...\n";
    return;
  }  

  std::cout << "\nYou are renting " << p->getCount() <<
    " books.\n";

  // gets books person is renting
  c = p->getBooks();

  // prints information of each book person is renting
  for(int i = 0; i < p->getCount(); i++)
    {
      b = findBookC(c[i], " ");
      std::cout << "* ";
      std::cout << b->getTitle(1);
      std::cout << "(" << c[i] << ") - ";
      b->special();
      std::cout << " ";
      b->printSpecial(0);
      std::cout << "\n";
    }
}

/*
library class - showBooks
------------------------------------------------------
Post : 
  - all books in the "library database" or 'tree' are printed along with all of their information
*/
void library :: showBooks()
{
  std::cout <<   
  "*********************************************\n";
  std::cout << std::setw(30) <<"Children Books:\n" <<
  "*********************************************\n";
  std::cout << "code" << std::setw(18) << "title" <<
    std::setw(13) << "age" << std::setw(12) << 
    "available" << std::setw(8) << "rented\n"; 
  std::cout << 
  "---------------------------------------------\n";
  printTree(tree[0]);

  std::cout <<
  "*********************************************\n";
  std::cout << std::setw(30) <<"Computer Books:\n" <<
  "*********************************************\n"; 
    std::cout << "code" << std::setw(18) << "title" <<
    std::setw(20) << "publisher" << std::setw(16) << 
    "available" << std::setw(10) << "rented\n"; 
  std::cout << 
  "---------------------------------------------\n";
  printTree(tree[1]);
  std::cout <<
  "*********************************************\n";
  std::cout << std::setw(20) << "Novels:\n" <<
  "*********************************************\n";
    std::cout << "code" << std::setw(18) << "title" <<
    std::setw(13) << "date" << std::setw(13) << 
    "available" << std::setw(10) << "rented\n"; 
  std::cout << 
  "---------------------------------------------\n";
  printTree(tree[2]);
}

/*
library class - getTree
------------------------------------------------------
Post : 
  - data from books.txt is input into 'tree'
*/
void library :: getTree()
{
  std::ifstream inFile;
  inFile.open("books.txt");

  while(!inFile.eof())
    {
      int c;    // code of book currently being extracted
      book *temp;// book pointer whose data is to be retrieved

      inFile >> c;
      getBook(c, inFile, temp);

      // book is input into the appropriate tree
      if(c <= 2000)
        buildTree(tree[0], temp);
      else if(c <= 3000)
        buildTree(tree[1], temp);
      else
        buildTree(tree[2], temp);

    }
  inFile.close();
}

/*
library class - getBook
  int c       
    - code of book whose data is to be extracted from given file
  ifstream in 
    - file in which data is being extracted from
------------------------------------------------------
Post : 
  - data is extracted from file according to its given code and input into book pointer 'temp'
*/
void library::getBook(int c, std::ifstream &in, book *&temp)
{
  std::string t;  // title of book
  int av, r;      // available / rented copies of book

  in >> t;

  // Specific data according to book type is retrieved
  if(c <= 2000)
  {
    int a;  // age reccomendation for book
    in >> a >> av >> r;
    temp = new ChildrenBook(c, t, av, r, a);
  }
  else if(c <=3000)
  {
    std::string p;  // publisher of book
    in >> p >> av >> r;
    temp = new ComputerBook(c, t, av, r, p);
  }
  else
  {
    int date;  // publish date of book
    in >> date >> av >> r;
    temp = new Novel(c, t, av, r, date);
  }
}

/*
library class - buildTree
  leaf<book> root:
    tree in which given book will be inserted in
  book val
    book pointer to be inserted into given tree 
------------------------------------------------------
Post : 
  - book pointer is inserted in its appropraite position in the given tree
*/
void library ::buildTree(leaf<book> *&root, book *val)
{
  if(root != NULL)
  {
    // if 'val' should be inserted on right side of root
    if(val->getCode() > root->data->getCode())
    {
      if(root->right == NULL)
        inputLeaf(root, 'R', val);
      else // continues to search for spot of 'val'
        buildTree(root->right, val);
    }
    else  //if 'val' should be input on left side of tree
    {
      if(root->left == NULL)
        inputLeaf(root, 'L', val);
      else // continues to search for spot of 'val'
        buildTree(root->left, val);
    }
  }// if tree is empty, root points to 'val'
  else 
    root = new leaf<book>(val);
}

/*
library class - inputLeaf
  leaf<book> parent:
    will point to 'val'
  char side:
    indicates if val will be right/left child
  book val
    book pointer to be input into tree
------------------------------------------------------
Post : 
  - parent will either point to 'val' or will be the parent of 'val' in which val will be a left or right child 
*/
void library :: inputLeaf(leaf<book> *parent, char side, book *val)
{
  leaf<book> *child;  // creates new leaf for 'val'
  child = new leaf<book>(val);

  // if parent is null then parent set equal to 'child'
  if(parent == NULL)
    parent = child; 
  else if(side == 'R')
    parent->right = child;
  else
    parent->left = child;
}

/*
library class - getList 
------------------------------------------------------
Post : 
  - data from person.txt is extracted and input into 'list'
*/
void library:: getList()
{
  person *temp;    // person object that is filled and enterd into 'list'
  std::ifstream inFile;  // file stream
  inFile.open("person.txt");

  while(!inFile.eof())
    {
      int id, rented, code;  // data to be extracted to form person object
      std::string name;  // name of person
      inFile >> id >> name >> rented;

      // creates appropriate person object
      if(id < 101)
        temp = new Teacher(id, name);
      else
        temp = new Student(id, name);

      // adds codes of rented books to persons list
      for(int i = 0; i < rented; i++)
        {
          inFile >> code;
          temp->checkOut(code);
        }
      
      // inputs person into appropriate list
      if(id < 101)
        inputNode(list[0], temp);
      else
        inputNode(list[1], temp);
    }
  inFile.close();
}

/*
library class - inputNode
  node<person> head:
    list in which given person will be added to
  person p
    person pointer to be inserted into given list 
------------------------------------------------------
Post : 
  - person pointer is inserted into given list
*/
void library::inputNode(node<person> *&head, person *p)
{
  // if list is empty
  if(head == NULL)
    head = new node<person>(p);
  else
  {
    // creates new node for 'p' and p is inserted at head of list
    node<person> *newP;
    newP = new node<person>(p);
    newP->next = head;
    head = newP;
  }
}

/*
library class - printTree
  leaf<book> root:
    given tree whose data is to be printed
------------------------------------------------------
Post : 
  - data from given tree is printed to standard output
*/
void library :: printTree(leaf<book> *root)
{
  // Prints contents of tree using inorder traversal
  if(root != NULL)
  {
    printTree(root->left);
    std::cout << root->data->getCode() << std::setw(25)        << root->data->getTitle(1);
    root->data->printSpecial(1);
    std::cout << std::setw(8)  
      << root->data->getAvailable() 
      << std::setw(9) << root->data->getRented() 
      << "\n";
    printTree(root->right);
  }
}

/*
library class - deleteTree
  leaf<book> root:
    tree in which its data is to be deleted 
------------------------------------------------------
Post : 
  - dynamic memory used in given tree is freed/ deleted
*/
void library ::deleteTree(leaf<book> *&root)
{
  if(root != NULL)
    {
      // if root has children -> continue search for leaf
      if(root->left != NULL)
        deleteTree(root->left);
      if(root->right != NULL)
        deleteTree(root->right);
      // if root has no children, it is deleted
      if(root->left == NULL && root->right == NULL)
      {
        delete root->data;
        delete root;
        root = NULL;
      } 
    }
}

/*
library class - deleteList
  node<person> head:
    list in which its data will be deleted
------------------------------------------------------
Post : 
  - dynamic memory from given list is deleted
*/
void library :: deleteList(node<person> *&head)
{
  node<person> *temp; // temp pointer to deleted each node
  
  while(head != NULL)
    {
      temp = head;
      head = head->next;
      delete temp->data;
      delete temp;
      temp = NULL;
    }
  head = NULL;
}

/*
library class - findBookC
  int code:
    code of book being searched for
  string t
    title of book being searched for
------------------------------------------------------
Post : 
  - if book is found, pointer of that book is returned
  - if not, pointer with code -1 is returned
*/
book* library::findBookC(int code, std::string t)
{
  book *temp;  // book pointer to be returned

  // searches appropriate list for given book type
  if(code < 2001)
    temp = searchC(tree[0], code);
  else if(code < 3001)
    temp = searchC(tree[1], code);
  else
    temp = searchC(tree[2], code);
  // if book is not found, failure message printed
  if(temp->getCode() == -1)
  {
    std::cout << "\n" << t << "(" << code << 
      ") does not exist.\n";
    return temp;
  }
  return temp;
}

/*
library class - searchC
  leaf<book> root:
    tree in which given book will be searched for
  int code
    code of book being searched for
------------------------------------------------------
Post : 
  - pointer of book is returned if found
  - if not, pointer with code of -1 is returned
*/
book* library::searchC(leaf<book> *root, int code)
{
  if(root != NULL)
  {
    // if book is found
    if(root->data->getCode() == code)
      return root->data;
    // continues to search for book
    if(code > root->data->getCode())
      return searchC(root->right, code);
    else 
      return searchC(root->left, code);
  }
  else
  {
    // if end of tree is reached without finding book
    book *temp = new book(-1, " ", -1,-1);
    return temp;
  }
}

/*
library class - searchT
  leaf<book> root:
    tree in which given book is searched for
  string t
    title of book being searched for 
------------------------------------------------------
Post : 
  - if book is found, pointer of that book is returned
  - if not, pointer with code of -1 is returned
*/
book* library::searchT(leaf<book> *root, std::string t)
{
  if(root != NULL)
  {
    // if title match is found
    if(root->data->getTitle(1) == t)
      return root->data;
    // if match not found->continue search
    if(root->left != NULL)
      return searchT(root->left, t);
    else
      return searchT(root->right, t);
  }
  else
  {
    // if end of tree is reached without finding book
    book *temp = new book(-1," ", -1, -1);
    return temp;
  }
}

/*
library class - findPerson
  node<person> head:
    list in which given person is searched for
  int id
    id of person to be searched for
------------------------------------------------------
Post : 
  - if person is found, pointer of that person is returned
  - if not, person pointer with id of -1 is returned
*/
person* library ::findPerson(node<person> *head, int id)
{
  node<person> *curr(head); // node used to traverse list

  while(curr != NULL)
    {
      if(curr->data->getID() == id)
        return curr->data;
      curr = curr->next;
    }

  // if entire list is searched but person is not found
  return new person(-1, " ");
}