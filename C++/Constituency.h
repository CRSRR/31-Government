#ifndef CONSTITUENCY_H
#define CONSTITUENCY_H

#include <string>
#include <vector>
#include "Member.h"

class Constituency {
private:
    std::string name;
    std::vector<Member> members;

public:
    // Constructor
    Constituency(const std::string& name);

    // Getter
    std::string getName() const;

    // Add a member
    void addMember(const Member& member);

    // Display information
    void displayInfo() const;
};

#endif // CONSTITUENCY_H
