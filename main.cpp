#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include <fstream>
#include <sstream>
#include <map>
#include <regex>
#include <iomanip>
#include <ctime>

class Date
{
public:
  Date(int day, int month, int year) : day(day), month(month), year(year) {}

  Date operator+(int days) const
  {
    return Date(day + days, month, year);
  }

private:
  int day;
  int month;
  int year;
};

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
private:
  // std::vector<Book *> booksBorrowed;
  int memberID;

public:
  Member(int id, const std::string &memberName, const std::string &memberAddress, const std::string &memberEmail) : memberID(id) {}

  Member() : memberID(0) {}

  int getMemberID() const
  {
    return memberID;
  }

  const std::vector<Book *> &getBooksBorrowed() const
  {
    return booksBorrowed;
  }

  void setBooksBorrowed(Book &book);
};

class Librarian
{
private:
  int staffId;
  int salary;

public:
  void addmember();

  void calcFine(const Member &member)
  {
    int totalFine = 0;

    for (const auto &book : member.getBooksBorrowed())
    {
      time_t currentDate;
      time_t dueDate = book->getDueDate();

      if (currentDate > dueDate)
      {
      }
    }

    std::cout << "Total fine for Member " << member.getMemberID() << ": £" << totalFine << "\n";
  }
};

class Book
{
private:
  string bookName;
  string authorFirstName;
  string authorLastName;
  string borrower;
  time_t dueDate;
  // Person *borrower;
  bool borrowed;
  vector<Book> availableBooks;

public:
  int bookID;
  string bookType;
  int pageCount;

  // Default constructor for my Book Class
  Book() : bookID(0), pageCount(0), bookName(""), authorFirstName(""), authorLastName(""), bookType("") {}

  Book(int id, const string &name, const string &firstName, const string &lastName) : bookID(id), bookName(name), authorFirstName(firstName), authorLastName(lastName), borrower(nullptr) {}

  // Getter methods
  int getbookID() const
  {
    return bookID;
  }

  string getbookName() const
  {
    return bookName;
  }

  string getAuthorfirstName() const
  {
    return authorFirstName;
  }

  string getAuthorLastName() const
  {
    return authorLastName;
  }

  time_t getDueDate() const
  {
    return dueDate;
  }

  void setDueDate(const time_t &newDueDate)
  {
    dueDate = newDueDate;
  }

  void returnBook();

  void borrowBook(Person &borrower, const time_t &dueDate);

  void issueBook(Member &member, Book &book)
  {
    if (std::find(availableBooks.begin(), availableBooks.end(), book) != availableBooks.end())
    {
      time_t currentDate;
      time_t dueDate = currentDate + 3;

      // book.issueBook(member, dueDate);
      member.setBooksBorrowed(book);

      std::cout << "Book has been issued successfully.\n";
    }
    else
    {
      std::cout << "Book not available for issue.\n";
    }
  }
};

vector<Book> readCSV(const string &filename);

int main()
{
  vector<Book> libraryBooks = readCSV("library_books.csv");

  Book book;
  Member member;
  Person person;
  string bookName;
  string userChoice;

  for (const auto &book : libraryBooks)
  {
    cout << "Book ID: " << book.getbookID() << ", "
         << "Book Name: " << book.getbookName() << ", "
         << "Author: " << book.getAuthorfirstName() << " " << book.getAuthorLastName() << ", "
         << "Book Type: " << book.bookType << std::endl;
  }

  cout << "Welcome to the library management system" << endl;
  cout << "What would you like to do?\nType your answer in lowercase and put a dash between words" << endl;
  cout << "Add Member | Issue Book | Return book | Display borrowed books" << endl;
  cin >> userChoice;
  cout << "You have selected " << userChoice << endl;

  if (userChoice == "add-member")
  {
    string newName;
    cout << "Enter member's name: ";
    getline(cin, newName);
    person.setName(newName);

    string newEmail;
    cout << "Enter member's email: ";
    getline(cin, newEmail);
    person.setEmail(newEmail);

    string newAddress;
    cout << "Enter member's address: ";
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
  }
  if (userChoice == "display-borrowed-books")
  {
  }
  if (userChoice == "return-book")
  {
  }

  return 0;
}