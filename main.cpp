/*
main.cpp
Author: student id
Created: 23/12/23
*/

#include <iostream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
#include <cctype>
#include <map>
#include <regex>
#include <iomanip>
#include <ctime>

class Person
{
private:
  string email;
  string address;
  string name;
public:
  string userChoice;
  string getName() const
  {
    return name;
  }
  void setName(const string &newName)
  {
    if (!newName.empty())
    {
      name = newName;
    }
    else
    {
      cout << "Name is not valid, return a name with characters" << endl;
    }
  }

  string getEmail() const
  {
    return email;
  }
  void setEmail(const string &newEmail)
  {
    regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    if (regex_match(newEmail, emailRegex))
    {
      email = newEmail;
      cout << "Email is valid." << endl;
    }
    else
    {
      cout << "Invalid email. Please provide a valid email address with correct email format." << endl;
    }
  }

  string getAddress() const
  {
    return address;
  }
  void setAddress(const string &newAddress)
  {
    if (newAddress.length() >= 5 && newAddress.length() <= 50)
    {
      address = newAddress;
      cout << "Address is valid." << endl;
    }
    else
    {
      cout << "Invalid address. Address length should be between 5 and 50 characters." << endl;
    }
  }
};

class Member
{
public:
  int memberId;
};

class Librarian
{
public:
  int staffId;
  int salary;
void addmember();
void issueBook(int )

};

class Book
{
public:
  int bookID;
  string bookName;
  string authorFirstName;
  string authorLastName;
  string bookType;
  string borrower;
  time_t dueDate;

  void setBorrower(Member *borrower)
  {
    this->borrower = borrower;
  }
  Book(int bookID, const string& bookName, const string& authorFirstName, const string& authorLastName)
        : bookID(bookID), bookName(bookName), authorFirstName(authorFirstName), authorLastName(authorLastName) {
        dueDate = 0;
    }
    void borrowBook(Member& borrower, time_t dueDate);
    void returnBook();

private:
  Member *borrower;
};

int main()
{
  Book book;
  Member member;
  Person person;
  string bookName;
  string userChoice;

  struct Book
  {
    int bookID;
    string bookName;
    string authorFirstName;
    string authorLastName;
  };

  map<int, Book> bookMap;
  bookMap[1] = {1, "The Great Gatsby", "F.Scott", "Fitzgerald"};
  bookMap[2] = {2, "To Kill a Mockingbird", "Harper", "Lee"};
  bookMap[3] = {3, "The Catcher in the Rye", "J.D.", "Salinger"};
  bookMap[4] = {4, "Pride and Prejudice", "Jane", "Austen"};

  cout << "Welcome to the library management system" << endl;
  cout << "What would you like to do?\nType your answer in lowercase and put a dash between words" << endl;
  cout << "Add Member | Issue Book | Return book | Display borrowed books" << endl;
  cin >> userChoice;
  cout << "You have selected " << userChoice << endl;

  if (userChoice == "add-member")
  {
  string newName;
  cout << "Enter name: ";
  getline(cin, newName);
  person.setName(newName);

  string newEmail;
  cout << "Enter email: ";
  getline(cin, newEmail);
  person.setEmail(newEmail);

  string newAddress;
  cout << "Enter address: ";
  getline(cin, newAddress);
  person.setAddress(newAddress);

   cout << "Member Information:" << endl;
  cout << "Name: " << person.getName() << "\n";
  cout << "Email: " << person.getEmail() << "\n";
  cout << "Address: " << person.getAddress() << "\n";

  return 0;
  }
  if (userChoice == "issue-book")
  {
//setBooksBorrowed(book : Book)
//string getMemberID()
//
  }
  if (userChoice == "display-borrowed-books")

  {
//getBooksBorrowed

  }
  if (userChoice == "return-book")
  {

  }
  return 0;
}

string getbookName()
{
  int userInputID;

  cout << "Enter book ID: " << endl;
  cin >> userInputID;

  Book book;
  book.bookID = userInputID;
  string bookName = book.getBookNameFromID(userInputID);

  cout << "Book Name: " << bookName << endl;

  string getBookNameFromID(int id)
  {
    auto it = bookMap.find(id);

    if (it != bookMap.end())
    {
      return it->second.bookName;
    }
    else
    {
      return "Book not found";
    }
  }
};
