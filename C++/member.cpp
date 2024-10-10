#include "Member.h"
#include <iostream>

// Constructor
Member::Member(const std::string& name, int age, const std::string& constituency, const std::string& party, const std::string& position)
    : name(name), age(age), constituency(constituency), party(party), position(position) {}

// Getters
std::string Member::getName() const { return name; }
int Member::getAge() const { return age; }
std::string Member::getConstituency() const { return constituency; }
std::string Member::getParty() const { return party; }
std::string Member::getPosition() const { return position; }

// Setters
void Member::setAge(int age) { this->age = age; }
void Member::setParty(const std::string& party) { this->party = party; }
void Member::setPosition(const std::string& position) { this->position = position; }

// Display method
void Member::displayInfo() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Constituency: " << constituency << std::endl;
    std::cout << "Party: " << party << std::endl;
    std::cout << "Position: " << position << std::endl;
}
