/**#define CATCH_CONFIG_MAIN

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <regex>
#include <iomanip>
#include <ctime>

TEST_CASE("Person Class Tests", "[person]")
{
    Person person;

    // To check if a name above 3 letters will work
    SECTION("Setting and getting member name")
    {
        person.setName("John Doe");
        REQUIRE(person.getName() == "John Doe");
    }

    // To check if an email containing @ will work
    SECTION("Setting and getting member email")
    {
        person.setEmail("john.doe@example.com");
        REQUIRE(person.getEmail() == "john.doe@example.com");
    }

    // To check if email is empty for invalid input
    SECTION("Setting invalid member email")
    {
        person.setEmail("invalid-email");
        REQUIRE(person.getEmail().empty());
    }

    // To check if setting a correct address between 5 and 50 characters will work
    SECTION("Setting and getting valid address")
    {
        person.setAddress("123 street");
        REQUIRE(person.getAddress() == "123 street");
    }

    // To check if address length is less than 5 characters
    SECTION("Setting invalid address")
    {
        person.setAddress("Short");
        REQUIRE(person.getAddress().empty());
    }
};*/