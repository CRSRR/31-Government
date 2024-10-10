#Author:Clayton
#Rollno:31
#Title:Goa Legislative Assembly
#Startdate:15-07-24
#Modifieddate:22-07-24
#Description:to show oop implementation in goa legislative assembly

class Member:
    def __init__(self, name, age, constituency, party, position):
        self.name = name
        self.age = age
        self.constituency = constituency
        self.party = party
        self.position = position

    def get_name(self):
        return self.name

    def get_age(self):
        return self.age

    def get_constituency(self):
        return self.constituency

    def get_party(self):
        return self.party

    def get_position(self):
        return self.position

    def set_age(self, age):
        self.age = age

    def set_party(self, party):
        self.party = party

    def set_position(self, position):
        self.position = position

    def display_info(self):
        print("Name:", self.name)
        print("Age:", self.age)
        print("Constituency:", self.constituency)
        print("Party:", self.party)
        print("Position:", self.position)
