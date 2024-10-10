#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member {
private:
    std::string name;
    int age;
    std::string constituency;
    std::string party;
    std::string position;

public:
    // Constructor
    Member(const std::string& name, int age, const std::string& constituency, const std::string& party, const std::string& position);

    // Getters
    std::string getName() const;
    int getAge() const;
    std::string getConstituency() const;
    std::string getParty() const;
    std::string getPosition() const;

    // Setters
    void setAge(int age);
    void setParty(const std::string& party);
    void setPosition(const std::string& position);

    // Display method
    void displayInfo() const;
};

#endif // MEMBER_H
