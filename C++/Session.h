#ifndef SESSION_H
#define SESSION_H

#include <string>
#include <vector>

class Session {
private:
    std::string sessionDate;
    int startHour;
    int startMinute;
    int endHour;
    int endMinute;
    std::string agenda;
    std::vector<std::string> topicsOfDiscussion;

    // Helper methods for validation
    void validateHour(int hour) const;
    void validateMinute(int minute) const;

public:
    // Constructor
    Session(const std::string& sessionDate, int startHour, int startMinute, int endHour, int endMinute, const std::string& agenda);

    // Setters
    void setStartHour(int startHour);
    void setStartMinute(int startMinute);
    void setEndHour(int endHour);
    void setEndMinute(int endMinute);

    // Add a topic of discussion
    void addTopicOfDiscussion(const std::string& topic);

    // Getter
    std::string getAgenda() const;

    // Display information
    void displayInfo() const;
};

#endif // SESSION_H
