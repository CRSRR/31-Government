#Author:Clayton
#Rollno:31
#Title:Goa Legislative Assembly
#Startdate:15-07-24
#Modifieddate:22-07-24
#Description:to show oop implementation in goa legislative assembly

class BillStatus:
    PROPOSED = "PROPOSED"
    PENDING = "PENDING"
    APPROVED = "APPROVED"
    REJECTED = "REJECTED"

class Bill:
    def __init__(self, title, description, proposer, date_introduced, status):
        self.title = title
        self.description = description
        self.proposer = proposer
        self.date_introduced = date_introduced
        self.status = status

    def get_title(self):
        return self.title

    def get_description(self):
        return self.description

    def get_proposer(self):
        return self.proposer

    def get_date_introduced(self):
        return self.date_introduced

    def get_status(self):
        return self.status

    def set_status(self, status):
        self.status = status

    def display_info(self):
        print("Bill Title:", self.title)
        print("Description:", self.description)
        print("Proposer:", self.proposer)
        print("Date Introduced:", self.date_introduced)
        print("Status:", self.status)