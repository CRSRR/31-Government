//Author:Clayton
//Rollno:31
//Title:Goa Legislative Assembly
//Startdate:15-07-24
//Modifieddate:22-07-24
//Description:to show oop implementation in goa legislative assembly


public class Bill {
    public enum BillStatus {
        PROPOSED,
        PENDING,
        APPROVED,
        REJECTED
    }

    private String title;
    private String description;
    private String proposer;
    private String dateIntroduced;
    private BillStatus status;

    public Bill(String title, String description, String proposer, String dateIntroduced, BillStatus status) {
        this.title = title;
        this.description = description;
        this.proposer = proposer;
        this.dateIntroduced = dateIntroduced;
        this.status = status;
    }

    public String getTitle() {
        return title;
    }

    public String getDescription() {
        return description;
    }

    public String getProposer() {
        return proposer;
    }

    public String getDateIntroduced() {
        return dateIntroduced;
    }

    public BillStatus getStatus() {
        return status;
    }

    public void setStatus(BillStatus status) {
        this.status = status;
    }

    public void displayInfo() {
        System.out.println("Bill Title: " + title);
        System.out.println("Description: " + description);
        System.out.println("Proposer: " + proposer);
        System.out.println("Date Introduced: " + dateIntroduced);
        System.out.println("Status: " + status);
    }
}