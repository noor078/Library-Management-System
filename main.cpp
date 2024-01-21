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
  Date(int day, int month, int year) : day(day), month(month), year(year) {}

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
  string userChoice;

  // Getter for retrieving the name of the person
  string getName() const
  {
    return name;
  }

  // Setter for updating the name with validation
  void setName(const string &newName)
  {
    if (name.length() >= 3 && name.length() <= 20)
    {
      name = newName;
    }
    else
    {
      cout << "Name is not valid, return a name with characters" << endl;
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

public:
  vector<Book *> booksBorrowed;

  // Default constructor for Member class
  Member() : memberID(0) {}

  // Constructor for Member class with initialisation
  Member(int id, const std::string &memberName, const std::string &memberAddress, const std::string &memberEmail) : memberID(id) {}

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
  Book(int id, const string &name, const string &firstName, const string &lastName) : bookID(id), bookName(name), authorFirstName(firstName), authorLastName(lastName), borrower(nullptr) {}

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

  // In order to return a borrowed book
  void returnBook();

  // In order to borrow a book with a specified due date
  void borrowBook(Person &borrower, const time_t &dueDate);

  // Function for issuing a book to a member with a specified due date
  void issueBook(Member &member, const time_t &dueDate)
  {
    setDueDate(dueDate);
  }

};

// Library class
class Librarian
{
private:
  int staffId;
  int salary;

public:
  // Function to issue a book to a member with a specified due date
void issueBookToMember(Member & member, Book & book, const time_t & dueDate);

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
 void Librarian::issueBookToMember(Member &member, Book &book, const time_t &dueDate)
{
  if (std::find(book.availableBooks.begin(), book.availableBooks.end(), book) != book.availableBooks.end())
  {
      book.issueBook(member, dueDate);
      member.setBooksBorrowed(book);

      std::cout << "Book has been issued successfully.\n";
    }
    else
    {
      std::cout << "Book not available for issue.\n";
    }
  }

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

vector<Book> readCSV(const string &filename);

// Main function of the Library Management System
int main()
{
    // In order to read books from a CSV file
  vector<Book> libraryBooks = readCSV("library_books.csv");

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
    cout << "Enter member's ID: " << endl;
    int memberID;
    cin >> memberID;
    member.setMemberID(memberID);
    // Display books borrowed by the member
    librarian.displayBorrowedBooks(member);
  }

  if (userChoice == "return-book")
  {
  }

  return 0;
}