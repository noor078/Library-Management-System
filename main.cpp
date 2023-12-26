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

int main() 
{
  string userChoice = "abc";
  
    cout << "Welcome to the library management system" << endl;
    cout << "What would you like to do?" << endl;
    cout << "Add Member | Issue Book | Return book | Display member's borrowed books" << endl;
    cin >> userChoice;
    cout << "You have selected " << userChoice << endl;

    return 0;
}

class Person
{
private:
std::string name;
std::string address;
std::string email;
public:

};

class Member
{
    private:
    int memberId;
};


std::string setEmail() {
    std::string email;
cout << "What would you like to set your email as?";
cout << "Type new email:";
cin >> email;
cout << "The email you have set is: " << email;
return email;
}

class Librarian
{
private:

};

void addMember() {
cout << "What's members name?";

}

