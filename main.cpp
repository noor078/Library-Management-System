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

// Date class
class Date
{
  // Constructor for the Date class
public:
  Date(int day, int month, int year)
      : day(day), month(month), year(year) {}

  // Overloaded addition operator to calculate a new date by adding days
  Date operator+(int days) const
  {
    return Date(day + days, month, year);
  }

private:
  int day;
  int month;
  int year;
};

// Person class
class Person
{
private:
  string email;
  string address;
  string name;

public:
  // Getter for retrieving the name of the person
  string getName() const
  {
    return name;
  }

  // Setter for updating the name with validation
  void setName(const string &newName)
  {
    if (newName.length() >= 3 && newName.length() <= 20)
    {
      name = newName;
    }
    else
    {
      cout << "Name is not valid, enter a name with 3 to 20 characters" << endl;
    }
  }

  // Getter for retrieving the email of the person
  string getEmail() const
  {
    return email;
  }

  // Setter for updating the email with email format validation
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

  // Getter for retrieving the address of the person
  string getAddress() const
  {
    return address;
  }

  // Setter for updating the address with length validation
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

// Member class
class Member
{
private:
  int memberID;
  string memberName;
  string memberAddress;
  string memberEmail;
  Person person;

public:
  vector<Book *> booksBorrowed;

  Member() : memberID(0) {}

  // Constructor for member details
  Member(int id, const std::string &memberName, const std::string &memberAddress, const std::string &memberEmail)
      : memberID(id)
  {
    person.setName(memberName);
    person.setAddress(memberAddress);
    person.setEmail(memberEmail);
  }

  // Getter method for retrieving the member ID
  int getMemberID() const
  {
    return memberID;
  }

  // Setter for updating the member ID
  void setMemberID(int &newMemberID)
  {
    memberID = newMemberID;
  }

  // Function adds a borrowed book to the member's list
  void setBooksBorrowed(Book &book)
  {
    booksBorrowed.push_back(&book);
  }

  // Getter for retrieving the list of books borrowed by the member
  const std::vector<Book *> &getBooksBorrowed() const
  {
    return booksBorrowed;
  }
};

// Book class
class Book
{
private:
  string bookName;
  string authorFirstName;
  string authorLastName;
  time_t dueDate;
  Person *borrower;
  bool borrowed;

public:
  vector<Book> availableBooks;
  int bookID;
  string bookType;
  int pageCount;

  // Overloaded equality operator for Book class
  bool operator==(const Book &other) const
  {
    return this->bookID == other.bookID;
  }

  // Default constructor for Book Class
  Book() : bookID(0), pageCount(0), bookName(""), authorFirstName(""), authorLastName(""), bookType("") {}

  // Constructor for Book class with initialisation
  Book(int id, const string &name, const string &firstName, const string &lastName)
      : bookID(id), bookName(name), authorFirstName(firstName), authorLastName(lastName), borrower(nullptr) {}

  // Getter for retrieving the book ID
  int getbookID() const
  {
    return bookID;
  }

  // Getter for retrieving the book name
  string getbookName() const
  {
    return bookName;
  }

  // Getter for retrieving the author's first name
  string getAuthorfirstName() const
  {
    return authorFirstName;
  }

  // Getter for retrieving the author's last name
  string getAuthorLastName() const
  {
    return authorLastName;
  }

  // Getter for retrieving the due date of the book
  time_t getDueDate() const
  {
    return dueDate;
  }

  // Setter for updating the due date of the book
  void setDueDate(const time_t &newDueDate)
  {
    dueDate = newDueDate;
  }

};

// Library class
class Librarian
{
private:
  int staffId;
  int salary;
  std::vector<Member> members;

public:
  // Default constructor for librarian
  Librarian() : staffId(0), salary(0) {}

  // Constructor to initialise librarian variables
  Librarian(int staffId, int salary) : staffId(staffId), salary(salary) {}

  // Function to issue a book to a member with a specified due date
  void issueBookToMember(Member &member, Book &book, const time_t &dueDate);

  // Function to add a new member
  void addmember();

  // Function to display borrowed books of a member
  void displayBorrowedBooks(const Member &member)
  {
    const std::vector<Book *> &borrowedBooks = member.getBooksBorrowed();

    if (!borrowedBooks.empty())
    {
      std::cout << "The books borrowed by member " << member.getMemberID() << ":\n";
      for (const auto &book : borrowedBooks)
      {
        time_t dueDate = book->getDueDate();
        std::cout << "Book ID: " << book->getbookID() << ", "
                  << "Book Name: " << book->getbookName() << ", "
                  << "Author: " << book->getAuthorfirstName() << " " << book->getAuthorLastName() << ", "
                  << "Due Date: " << std::put_time(std::localtime(&dueDate), "%Y-%m-%d %H:%M:%S") << std::endl;
      }
    }
    else
    {
      std::cout << "No books borrowed by Member ID " << member.getMemberID() << ".\n";
    }
  }
};

// Function for reading data source file and returning a vector of books
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

// Main function of the Library Management System
int main()
{
  // In order to read books from a CSV file, put books into a vector
  vector<Book> libraryBooks = readCSV("library_books.csv");

  // Storing members into a vector
  vector<Member> members;

  // Creating instances of my classes: Book, Member, Person, and Librarian
  Book book;
  Member member;
  Person person;
  string bookName;
  string userChoice;
  Librarian librarian;
  string filename;

  // To display information about available library books
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
  cin.ignore();
  // Start menu for user choices
  cout << "What would you like to do?\nType your answer in lowercase and put a dash between words" << endl;
  cout << "Add Member | Issue Book | Return book | Display borrowed books" << endl;
  getline(cin, userChoice);
  cout << "You have selected " << userChoice << endl;

  // Adding a member functionality
  // Allows the user to enter member's name, email and address following correct validations
  if (userChoice == "add-member")
  {
    // Entering member's name with validations
    string newName;
    do
    {
      cout << "Enter member's name (3 to 20 characters): " << endl;
      getline(cin, newName);
      person.setName(newName);
    } while (newName.empty());

    // Entering member's email with validations
    string newEmail;
    do
    {
      cout << "Enter member's email: ";
      getline(cin, newEmail);
      person.setEmail(newEmail);
    } while (newEmail.empty());

    // Entering member's address with validations
    string newAddress;
    do
    {
      cout << "Enter member's address (5 to 50 characters): ";
      getline(cin, newAddress);
      person.setAddress(newAddress);
    } while (newAddress.empty());

    // Information about member stored
    cout << "You have saved the following details:" << endl;
    cout << "Member name: " << person.getName() << "\n";
    cout << "Member email: " << person.getEmail() << "\n";
    cout << "Member address: " << person.getAddress() << "\n";

    // Setting of member ID
    int memberID;
    cout << "Enter member's ID: ";
    cin >> memberID;
    member.setMemberID(memberID);

    // Member entered into vector of members
    members.push_back(member);
    cout << "Member has been added successfully" << endl;
    return 0;
  }

  // Faced problems with logic of issuing book and so decided to omit in order to have code successfully run
  if (userChoice == "issue-book")
  {
  }

  if (userChoice == "display-borrowed-books")
  {
    cout << "Enter member's ID: " << endl;
    int memberID;
    cin >> memberID;

// Checking if member ID can be found within vector of members
    auto it = std::find_if(members.begin(), members.end(), [memberID](const Member &member) {
        return member.getMemberID() == memberID;
    });

    if (it != members.end())
    {
         librarian.displayBorrowedBooks(*it);
    }
    else
    {
        cout << "Member with ID " << memberID << " not found." << endl;
    }}

  // Faced problems with logic of return book and so decided to omit in order to have code run
  if (userChoice == "return-book")
  {
  }

  return 0;
}