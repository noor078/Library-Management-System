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

// Forward declaration of book class
class Book;

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
  int memberID;

public:
  vector<Book *> booksBorrowed;

  Member() : memberID(0) {}

  Member(int id, const std::string &memberName, const std::string &memberAddress, const std::string &memberEmail) : memberID(id) {}

  int getMemberID() const
  {
    return memberID;
  }

void setBooksBorrowed(Book &book)
  {
    booksBorrowed.push_back(&book);
  }

  const std::vector<Book *> &getBooksBorrowed() const
  {
    return booksBorrowed;
  }
};

class Librarian
{
private:
  int staffId;
  int salary;

public:
  void addmember();

  void displayBorrowedBooks(const Member &member)
  {
    const std::vector<Book *> &borrowedBooks = member.getBooksBorrowed();

    if (!borrowedBooks.empty())
    {
      std::cout << "Books borrowed by Member ID " << member.getMemberID() << ":\n";
      for (const auto &book : borrowedBooks)
      {
        std::cout << "Book ID: " << book->getbookID() << ", "
                  << "Book Name: " << book->getbookName() << ", "
                  << "Author: " << book->getAuthorfirstName() << " " << book->getAuthorLastName() << ", "
                  << "Due Date: " << std::put_time(std::localtime(&book->getDueDate()), "%Y-%m-%d %H:%M:%S") << std::endl;
      }
    }
    else
    {
      std::cout << "No books borrowed by Member ID " << member.getMemberID() << ".\n";
    }
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

  bool operator==(const Book &other) const
  {
    return this->bookID == other.bookID;
  }
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

      //book.issueBook(member, dueDate);
      member.setBooksBorrowed(book);

      std::cout << "Book has been issued successfully.\n";
    }
    else
    {
      std::cout << "Book not available for issue.\n";
    }
  }
};

// Function for reading data source file
vector<Book> readCSV(const string &filename)
{
  vector<Book> books;

  ifstream file(filename);
  if (!file.is_open())
  {
    cerr << "Error opening data source file" << endl;
    return books;
  }

  string line;
  getline(file, line);

  while (getline(file, line))
  {
    istringstream iss(line);
    string token;

    int id;
    string name, authorFirstName, authorLastName, bookType;
    int pageCount;

    if (getline(iss, token, '\t'))
      id = stoi(token);
    if (getline(iss, name, '\t') &&
        getline(iss, token, '\t'))
      pageCount = stoi(token);
    if (getline(iss, authorFirstName, '\t') &&
        getline(iss, authorLastName, '\t') &&
        getline(iss, bookType, '\t'))
    {
      books.emplace_back(id, name, authorFirstName, authorLastName);
      books.back().pageCount = pageCount;
      books.back().bookType = bookType;
    }
  }

  file.close();
  return books;
}

vector<Book> readCSV(const string &filename);

int main()
{
  vector<Book> libraryBooks = readCSV("library_books.csv");

  Book book;
  Member member;
  Person person;
  string bookName;
  string userChoice;
  Librarian librarian;
  string filename;

  for (const auto &book : libraryBooks)
  {
    cout << "Book ID: " << book.getbookID() << ", "
         << "Book Name: " << book.getbookName() << ", "
         << "Author: " << book.getAuthorfirstName() << " " << book.getAuthorLastName() << ", "
         << "Book Type: " << book.bookType << std::endl;
  }

  // Main menu of Library Management System
  // Enabling user choices, prompts of what action they would like to complete
  cout << "Welcome to the library management system" << endl;

  // Enables user to independantly input CSV data file name to be used in accessing books
  cout << "Enter the data file name to access all the necessary library books" << endl;
  cin >> filename;

  cout << "What would you like to do?\nType your answer in lowercase and put a dash between words" << endl;
  cout << "Add Member | Issue Book | Return book | Display borrowed books" << endl;
  cin >> userChoice;
  cout << "You have selected " << userChoice << endl;

  // Adding a member functionality
  // Allows the user to enter member's name, email and address following correct validations
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
    cout << "Type -1 to return to restart Library Management System" << endl;
    cin >> userChoice;

    return 0;
  }
  if (userChoice == "issue-book")
  {
  }
  if (userChoice == "display-borrowed-books")
  {
    librarian.displayBorrowedBooks(member);
  }
  if (userChoice == "return-book")
  {
  }

  return 0;
}