#include "Bill.h"
#include <iostream>
#include <stdexcept>

// Constructor
Bill::Bill(const std::string& title, const std::string& description, const std::string& proposer, const std::string& dateIntroduced, BillStatus status)
    : title(title), description(description), proposer(proposer), dateIntroduced(dateIntroduced), status(status) {}

// Getters
std::string Bill::getTitle() const { return title; }
std::string Bill::getDescription() const { return description; }
std::string Bill::getProposer() const { return proposer; }
std::string Bill::getDateIntroduced() const { return dateIntroduced; }
Bill::BillStatus Bill::getStatus() const { return status; }

// Setters
void Bill::setStatus(BillStatus status) { this->status = status; }

// Display information
void Bill::displayInfo() const {
    std::cout << "Bill Title: " << title << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Proposer: " << proposer << std::endl;
    std::cout << "Date Introduced: " << dateIntroduced << std::endl;
    std::cout << "Status: " << statusToString(status) << std::endl;
}

// Utility methods for status conversion
std::string Bill::statusToString(BillStatus status) {
    switch (status) {
        case PROPOSED: return "Proposed";
        case PENDING: return "Pending";
        case APPROVED: return "Approved";
        case REJECTED: return "Rejected";
        default: throw std::invalid_argument("Unknown status");
    }
}

Bill::BillStatus Bill::stringToStatus(const std::string& statusStr) {
    if (statusStr == "Proposed") return PROPOSED;
    if (statusStr == "Pending") return PENDING;
    if (statusStr == "Approved") return APPROVED;
    if (statusStr == "Rejected") return REJECTED;
    throw std::invalid_argument("Invalid status string");
}
