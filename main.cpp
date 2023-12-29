/*
main.cpp
Author: student id
Created: 23/12/23
Updated:
*/

#include <iostream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
#include <cctype>

int main()
{
  string userChoice;
  string setEmail();
  int memberId;
  string email;
  string address;
  string name;

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
    cout << "Type member's name:" << endl;
    cin >> name;
    cout << "Type member's email:" << endl;
    cin >> email;
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
    if (address.length() >= 5 && address.length() <= 50) {
cout << "Address is valid." << endl;
    } else {
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

class Person
{
private:
  string name;
  string address;
  string email;
};

class Librarian
{
private:
  int staffId;
  int salary;
};

class Member
{
private:
  int memberId;
};

class Book
{
private:
  int bookID;
  string bookName;
  string authorFirstName;
  string authorLastName;
  string bookType;
  int dueDate;
};

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
