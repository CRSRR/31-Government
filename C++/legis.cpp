#include <iostream>
#include <vector>
#include <string>

class Member {
private:
    std::string name, constituency, party, position;
    int age;

public:
    Member(const std::string& name, int age, const std::string& constituency, const std::string& party, const std::string& position)
        : name(name), age(age), constituency(constituency), party(party), position(position) {}

    void display() const {
        std::cout << "Name: " << name << "\nAge: " << age << "\nConstituency: " << constituency
                  << "\nParty: " << party << "\nPosition: " << position << std::endl;
    }

    std::string getConstituency() const {
        return constituency;
    }
};

class Bill {
public:
    enum class Status { PROPOSED, PENDING, APPROVED, REJECTED };

private:
    std::string title, description, proposer, dateIntroduced;
    Status status;

public:
    Bill(const std::string& title, const std::string& description, const std::string& proposer, const std::string& dateIntroduced, Status status)
        : title(title), description(description), proposer(proposer), dateIntroduced(dateIntroduced), status(status) {}

    void display() const {
        std::cout << "Title: " << title << "\nDescription: " << description << "\nProposer: " << proposer
                  << "\nDate Introduced: " << dateIntroduced << "\nStatus: " << static_cast<int>(status) << std::endl;
    }

    static Status stringToStatus(const std::string& s) {
        if (s == "Proposed") return Status::PROPOSED;
        if (s == "Pending") return Status::PENDING;
        if (s == "Approved") return Status::APPROVED;
        return Status::REJECTED;
    }
};

class Session {
private:
    std::string date, agenda;
    int startHour, startMinute, endHour, endMinute;
    std::vector<std::string> topics;

public:
    Session(const std::string& date, int startHour, int startMinute, int endHour, int endMinute, const std::string& agenda)
        : date(date), startHour(startHour), startMinute(startMinute), endHour(endHour), endMinute(endMinute), agenda(agenda) {}

    void addTopic(const std::string& topic) {
        topics.push_back(topic);
    }

    void display() const {
        std::cout << "Date: " << date << "\nStart Time: " << startHour << ":" << startMinute
                  << "\nEnd Time: " << endHour << ":" << endMinute << "\nAgenda: " << agenda << "\nTopics:";
        for (const auto& topic : topics) std::cout << "\n - " << topic;
        std::cout << std::endl;
    }
};

class Constituency {
private:
    std::string name;
    std::vector<Member> members;

public:
    Constituency(const std::string& name) : name(name) {}

    void addMember(const Member& member) {
        members.push_back(member);
    }

    std::string getName() const {
        return name;
    }

    void display() const {
        std::cout << "Constituency: " << name << "\nMembers:";
        for (const auto& member : members) member.display();
        std::cout << std::endl;
    }
};

class Legis {
private:
    std::vector<Member> members;
    std::vector<Bill> bills;
    std::vector<Session> sessions;
    std::vector<Constituency> constituencies;

    template<typename T>
    T readInput(const std::string& prompt) {
        T value;
        std::cout << prompt;
        std::cin >> value;
        std::cin.ignore();
        return value;
    }

    std::string readString(const std::string& prompt) {
        std::string value;
        std::cout << prompt;
        std::getline(std::cin, value);
        return value;
    }

    Bill::Status readBillStatus() {
        std::string statusStr;
        Bill::Status status;
        while (true) {
            statusStr = readString("Enter status (Proposed, Pending, Approved, Rejected): ");
            try {
                status = Bill::stringToStatus(statusStr);
                return status;
            } catch (...) {
                std::cout << "Invalid status. Try again." << std::endl;
            }
        }
    }

    Constituency* findConstituency(const std::string& name) {
        for (auto& c : constituencies) {
            if (c.getName() == name) return &c;
        }
        return nullptr;
    }

public:
    void run() {
        while (true) {
            std::cout << "1. Add Member\n2. View Members\n3. Add Bill\n4. Create Session\n5. View Sessions\n6. View Constituencies\n0. Exit\n";
            int choice = readInput<int>("Enter choice: ");

            switch (choice) {
                case 1: {
                    std::string name = readString("Enter member name: ");
                    int age = readInput<int>("Enter age: ");
                    std::string constituency = readString("Enter constituency: ");
                    std::string party = readString("Enter party: ");
                    std::string position = readString("Enter position: ");
                    members.emplace_back(name, age, constituency, party, position);
                    auto* cons = findConstituency(constituency);
                    if (!cons) {
                        constituencies.emplace_back(constituency);
                        cons = &constituencies.back();
                    }
                    cons->addMember(members.back());
                    break;
                }
                case 2:
                    for (const auto& member : members) member.display();
                    break;
                case 3: {
                    std::string title = readString("Enter bill title: ");
                    std::string description = readString("Enter bill description: ");
                    std::string proposer = readString("Enter proposer: ");
                    std::string dateIntroduced = readString("Enter date introduced: ");
                    auto status = readBillStatus();
                    bills.emplace_back(title, description, proposer, dateIntroduced, status);
                    break;
                }
                case 4: {
                    std::string date = readString("Enter session date: ");
                    int startHour = readInput<int>("Enter start hour: ");
                    int startMinute = readInput<int>("Enter start minute: ");
                    int endHour = readInput<int>("Enter end hour: ");
                    int endMinute = readInput<int>("Enter end minute: ");
                    std::string agenda = readString("Enter agenda: ");
                    Session session(date, startHour, startMinute, endHour, endMinute, agenda);
                    std::string addTopic;
                    do {
                        std::string topic = readString("Enter topic of discussion: ");
                        session.addTopic(topic);
                        addTopic = readString("Add another topic? (yes/no): ");
                    } while (addTopic == "yes");
                    sessions.push_back(session);
                    break;
                }
                case 5:
                    for (const auto& session : sessions) session.display();
                    break;
                case 6:
                    for (const auto& constituency : constituencies) constituency.display();
                    break;
                case 0:
                    return;
                default:
                    std::cout << "Invalid choice." << std::endl;
            }
        }
    }
};

int main() {
    Legis legis;
    legis.run();
    return 0;
}

