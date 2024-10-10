#Author:Clayton
#Rollno:31
#Title:Goa Legislative Assembly
#Startdate:15-07-24
#Modifieddate:22-07-24
#Description:to show oop implementation in goa legislative assembly
from enum import Enum

# Member class definition
class Member:
    def __init__(self, name, age, constituency, party, position):
        self.name = name
        self.age = age
        self.constituency = constituency
        self.party = party
        self.position = position

    def display_info(self):
        print(f"Name: {self.name}, Age: {self.age}, Constituency: {self.constituency}, Party: {self.party}, Position: {self.position}")

class BillStatus(Enum):
    PROPOSED = "Proposed"
    PENDING = "Pending"
    APPROVED = "Approved"
    REJECTED = "Rejected"


class Bill:
    def __init__(self, title, description, proposer, date_intro, status):
        self.title = title
        self.description = description
        self.proposer = proposer
        self.date_intro = date_intro
        self.status = status

# Session class definition
class Session:
    def __init__(self, session_date, start_hour, start_minute, end_hour, end_minute, agenda):
        self.session_date = session_date
        self.start_hour = start_hour
        self.start_minute = start_minute
        self.end_hour = end_hour
        self.end_minute = end_minute
        self.agenda = agenda
        self.topics_of_discussion = []

    def add_topic_of_discussion(self, topic):
        self.topics_of_discussion.append(topic)

# Constituency class definition
class Constituency:
    def __init__(self, name):
        self.name = name
        self.members = []

    def add_member(self, member):
        self.members.append(member)

# Main program
def main():
    members = []
    bills = []
    sessions = []
    constituencies = []

    while True:
        print("Welcome to Goa Legislative Assembly")
        print("1. Add Member")
        print("2. View Members")
        print("3. Add Bill")
        print("4. Create Session")
        print("5. See Sessions created")
        print("6. View Constituencies")
        print("0. EXIT")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            add_member(members, constituencies)
        elif choice == 2:
            display_members(members)
        elif choice == 3:
            add_bill(bills, members)
        elif choice == 4:
            create_session(sessions)
        elif choice == 5:
            see_sessions(sessions)
        elif choice == 6:
            view_constituencies(constituencies)
        elif choice == 0:
            print("Exiting program...")
            break
        else:
            print("Invalid choice. Please enter a number from 0 to 6.")

def add_member(members, constituencies):
    name = input("Enter member's name: ")
    age = int(input("Enter member's age: "))
    constituency_name = input("Enter member's constituency: ")
    party = input("Enter member's party: ")
    position = input("Enter member's position: ")

    constituency = create(constituency_name, constituencies)

    member = Member(name, age, constituency, party, position)
    members.append(member)
    constituency.add_member(member)

    print(f"Member {name} successfully added {constituency_name}.")

def create(constituency_name, constituencies):
    for constituency in constituencies:
        if constituency.name == constituency_name:
            return constituency
    # If constituency not found, create a new one
    new_constituency = Constituency(constituency_name)
    constituencies.append(new_constituency)
    return new_constituency

def display_members(members):
    if not members:
        print("No members found.")
    else:
        print("List of Members:")
        for member in members:
            member.display_info()

def add_bill(bills, members):
    title = input("Enter title of the bill: ")
    description = input("Enter description of the bill: ")
    proposer_name = input("Enter name of the bill proposer: ")

    # Find the proposer member object
    proposer = find_member_by_name(proposer_name, members)
    if proposer:
        date_intro = input("Enter date of introduction (YYYY-MM-DD): ")
        status = input("Enter status of the bill (Proposed/Pending/Approved/Rejected): ")

        # Validate status input against BillStatus enum
        status = validate_bill_status(status)

        bill = Bill(title, description, proposer, date_intro, status)
        bills.append(bill)
        print(f"Bill '{title}' added successfully.")
    else:
        print(f"Member '{proposer_name}' not found.")

def find_member_by_name(name, members):
    for member in members:
        if member.name == name:
            return member
    return None

def validate_bill_status(status):
    try:
        return BillStatus[status.upper()].value
    except KeyError:
        print("Invalid bill status. Defaulting to 'Proposed'.")
        return BillStatus.PROPOSED.value

def create_session(sessions):
    session_date = input("Enter session date (YYYY-MM-DD): ")
    start_hour = int(input("Enter starting hour (0-23): "))
    start_minute = int(input("Enter starting minute (0-59): "))
    end_hour = int(input("Enter ending hour (0-23): "))
    end_minute = int(input("Enter ending minute (0-59): "))
    agenda = input("Enter session agenda: ")

    session = Session(session_date, start_hour, start_minute, end_hour, end_minute, agenda)
    sessions.append(session)
    print("Session created successfully.")

def see_sessions(sessions):
    if not sessions:
        print("No sessions created yet.")
    else:
        print("Sessions created:")
        for idx, session in enumerate(sessions, start=1):
            print(f"Session {idx}:")
            print(f"Date: {session.session_date}")
            print(f"Time: {session.start_hour}:{session.start_minute} - {session.end_hour}:{session.end_minute}")
            print(f"Agenda: {session.agenda}")
            if session.topics_of_discussion:
                print("Topics of Discussion:")
                for topic in session.topics_of_discussion:
                    print(f"- {topic}")

def view_constituencies(constituencies):
    if not constituencies:
        print("No constituencies found.")
    else:
        print("List of Constituencies:")
        for constituency in constituencies:
            print(f"- {constituency.name}")

if __name__ == "__main__":
    main()

    
   