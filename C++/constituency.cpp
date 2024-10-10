#include "Constituency.h"
#include <iostream>

// Constructor
Constituency::Constituency(const std::string& name) : name(name) {}

// Getter
std::string Constituency::getName() const { return name; }

// Add a member
void Constituency::addMember(const Member& member) {
    members.push_back(member);
}

// Display information
void Constituency::displayInfo() const {
    std::cout << "Constituency: " << name << std::endl;
    std::cout << "Members:" << std::endl;
    for (const auto& member : members) {
        member.displayInfo();
    }
}
