#Author:Clayton
#Rollno:31
#Title:Goa Legislative Assembly
#Startdate:15-07-24
#Modifieddate:22-07-24
#Description:to show oop implementation in goa legislative assembly

class Session:
    def __init__(self, session_date, start_hour, start_minute, end_hour, end_minute, agenda):
        self.session_date = session_date
        self.set_start_hour(start_hour)
        self.set_start_minute(start_minute)
        self.set_end_hour(end_hour)
        self.set_end_minute(end_minute)
        self.agenda = agenda
        self.topics_of_discussion = []

    def set_start_hour(self, start_hour):
        if not 0 <= start_hour <= 23:
            raise ValueError("Hour must be between 0 and 23.")
        self.start_hour = start_hour

    def set_start_minute(self, start_minute):
        if not 0 <= start_minute <= 59:
            raise ValueError("Minute must be between 0 and 59.")
        self.start_minute = start_minute

    def set_end_hour(self, end_hour):
        if not 0 <= end_hour <= 23:
            raise ValueError("Hour must be between 0 and 23.")
        self.end_hour = end_hour

    def set_end_minute(self, end_minute):
        if not 0 <= end_minute <= 59:
            raise ValueError("Minute must be between 0 and 59.")
        self.end_minute = end_minute

    def add_topic_of_discussion(self, topic):
        self.topics_of_discussion.append(topic)

    def get_agenda(self):
        return self.agenda

    def display_info(self):
        print("Session Date:", self.session_date)
        print(f"Start Time: {self.start_hour:02d}:{self.start_minute:02d}")
        print(f"End Time: {self.end_hour:02d}:{self.end_minute:02d}")
        print("Agenda:", self.agenda)
        print("Topics of Discussion:")
        for topic in self.topics_of_discussion:
            print("LIST-", topic)