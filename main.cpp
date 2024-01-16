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

class Person {
  public:
    string email;
  string address;
  string name;
  string userChoice;
  string getName();
  string setName();
  string getAddress();
  string setAddress();
  string getEmail() const{ 
    return name;
  };
  string setEmail();

void se

};

class Member {
  public:
  int memberId;
};

class Librarian {
  public:
int staffId;
int salary;
};

class Book {
  public:
int bookID;
string bookName;
string authorFirstName;
string authorLastName;
string bookType;
string dueDate;
string borrower;
void setBorrower(Member* borrower) {
  this->borrower = borrower;
}
private:
Member* borrower;
};

int main()
{
  Book book;
  Member member;
  string setEmail();
  string getName();
  string bookName;
string userChoice;

struct Book
{
  int bookID;
  string bookName;
  string authorFirstName;
  string authorLastName;
};

  std::map<int, Book> bookMap;
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
    cout << "Type member's ID (between 3 and 7 characters):" << endl;
    cin >> memberId;
    if (memberId >= 100 && memberId <= 9999999)
    {
      cout << "Member ID is valid." << endl;
    }
    else
    {
      cout << "Member ID must be between 3 and 7 characters." << endl;
    }
    //cout << "Type member's name:" << endl;
    //cin >> name;
    //cout << "Type member's email:" << endl;
    // cin >> email;
    if (email.find('@') != std::string::npos)
    {
      cout << "Member email is valid" << endl;
    }
    else
    {
      cout << "ERROR: Please type a valid email, containing an @" << endl;
      cin >> email;
    }
    cout << "Type member's address:" << endl;
    cin >> address;
    if (address.length() >= 5 && address.length() <= 50)
    {
      cout << "Address is valid." << endl;
    }
    else
    {
      cout << "ERROR: Address must be between 5 and 50 characters." << endl;
      cin >> address;
    }
  }

  if (userChoice == "issue-book")
  {
  }
  if (userChoice == "display-borrowed-books")
  {
  }
  if (userChoice == "return-book")
  {
  }
  return 0;
}

string getName() {
 cout << "Type member's name:" << endl;
    cin >> name;
};
string setName() {
  
}
string getAddress() {

}
string setAddress() {

}
string getEmail() {

}
string setEmail() {

}

string setEmail()
{
  string email;
  string userChoice;

  cout << "What would you like to set your email as?" << endl;
  cout << "Type new email:" << endl;
  cin >> email;
  cout << "The email you have set is " << email << endl;
  cout << "Correct? Yes/No" << endl;
  cin >> userChoice;
  if (userChoice == "no")
  {
    cout << "Type new email:" << endl;
    cin >> email;
    cout << "The email you have set is " << email << endl;
    cout << "Correct? Yes/No" << endl;
    cin >> userChoice;
  }
  return email;
}

void addMember()
{
  cout << "What's members name?";
}

string getbookName() {
    int userInputID;
    
    cout << "Enter book ID: " << endl;
    cin >> userInputID;

    Book book;
    book.bookID = userInputID;
    string bookName = book.getBookNameFromID(userInputID);

    cout << "Book Name: " << bookName << endl;

 string getBookNameFromID(int id) {
        auto it = bookMap.find(id);

        if (it != bookMap.end()) {
            return it->second.bookName;
        } else {
            return "Book not found";
        }
    }
};
 