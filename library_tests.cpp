#define CATCH_CONFIG_MAIN

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <regex>
#include <iomanip>
#include <ctime>

TEST_CASE("Person Class Tests", "[person]") {
    Person person;

    SECTION("Setting and getting member name") {
        person.setName("John Doe");
        REQUIRE(person.getName() == "John Doe");
    }

    SECTION("Setting and getting member email") {
        person.setEmail("john.doe@example.com");
        REQUIRE(person.getEmail() == "john.doe@example.com");
    }

    SECTION("Setting invalid member email") {
        person.setEmail("invalid-email");
        // Check if email is empty for invalid input
        REQUIRE(person.getEmail().empty()); 
    }

    SECTION("Setting and getting valid address") {
        person.setAddress("123 street");
        REQUIRE(person.getAddress() == "123 street");
    }

    SECTION("Setting invalid address") {
       // Checking if address length is less than 5 characters
        person.setAddress("Short");
        // Check if address is empty for invalid input
        REQUIRE(person.getAddress().empty()); 
    }
};