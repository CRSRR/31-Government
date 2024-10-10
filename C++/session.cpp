#include "Session.h"
#include <iostream>
#include <stdexcept>

// Constructor
Session::Session(const std::string& sessionDate, int startHour, int startMinute, int endHour, int endMinute, const std::string& agenda)
    : sessionDate(sessionDate), agenda(agenda) {
    setStartHour(startHour);
    setStartMinute(startMinute);
    setEndHour(endHour);
    setEndMinute(endMinute);
}

// Helper methods for validation
void Session::validateHour(int hour) const {
    if (hour < 0 || hour > 23) {
        throw std::invalid_argument("Hour must be between 0 and 23.");
    }
}

void Session::validateMinute(int minute) const {
    if (minute < 0 || minute > 59) {
        throw std::invalid_argument("Minute must be between 0 and 59.");
    }
}

// Setters
void Session::setStartHour(int startHour) {
    validateHour(startHour);
    this->startHour = startHour;
}

void Session::setStartMinute(int startMinute) {
    validateMinute(startMinute);
    this->startMinute = startMinute;
}

void Session::setEndHour(int endHour) {
    validateHour(endHour);
    this->endHour = endHour;
}

void Session::setEndMinute(int endMinute) {
    validateMinute(endMinute);
    this->endMinute = endMinute;
}

// Add a topic of discussion
void Session::addTopicOfDiscussion(const std::string& topic) {
    topicsOfDiscussion.push_back(topic);
}

// Getter
std::string Session::getAgenda() const {
    return agenda;
}

// Display information
void Session::displayInfo() const {
    std::cout << "Session Date: " << sessionDate << std::endl;
    std::cout << "Start Time: " << (startHour < 10 ? "0" : "") << startHour << ":" << (startMinute < 10 ? "0" : "") << startMinute << std::endl;
    std::cout << "End Time: " << (endHour < 10 ? "0" : "") << endHour << ":" << (endMinute < 10 ? "0" : "") << endMinute << std::endl;
    std::cout << "Agenda: " << agenda << std::endl;
    std::cout << "Topics of Discussion:" << std::endl;
    for (const auto& topic : topicsOfDiscussion) {
        std::cout << " - " << topic << std::endl;
    }
}
