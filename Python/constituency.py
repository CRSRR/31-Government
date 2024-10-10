#Author:Clayton
#Rollno:31
#Title:Goa Legislative Assembly
#Startdate:15-07-24
#Modifieddate:22-07-24
#Description:to show oop implementation in goa legislative assembly

class Member:
    def __init__(self, name, party):
        self.name = name
        self.party = party
    
    def display_info(self):
        print(f"Name: {self.name}, Party: {self.party}")

class Constituency:
    def __init__(self, name):
        self.name = name
        self.members = []
    
    def get_name(self):
        return self.name
    
    def add_member(self, member):
        self.members.append(member)
    
    def display_info(self):
        print(f"Constituency: {self.name}")
        print("Members:")
        for member in self.members:
            member.display_info()

