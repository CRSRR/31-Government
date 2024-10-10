#ifndef BILL_H
#define BILL_H

#include <string>

class Bill {
public:
    // Enum for BillStatus
    enum BillStatus {
        PROPOSED,
        PENDING,
        APPROVED,
        REJECTED
    };

private:
    std::string title;
    std::string description;
    std::string proposer;
    std::string dateIntroduced;
    BillStatus status;

public:
    // Constructor
    Bill(const std::string& title, const std::string& description, const std::string& proposer, const std::string& dateIntroduced, BillStatus status);

    // Getters
    std::string getTitle() const;
    std::string getDescription() const;
    std::string getProposer() const;
    std::string getDateIntroduced() const;
    BillStatus getStatus() const;

    // Setters
    void setStatus(BillStatus status);

    // Display information
    void displayInfo() const;

    // Utility methods for status conversion
    static std::string statusToString(BillStatus status);
    static BillStatus stringToStatus(const std::string& statusStr);
};

#endif // BILL_H
