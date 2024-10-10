// Author: Clayton
// Rollno: 31
// Title: Goa Legislative Assembly
// Startdate: 15-07-24
// Modifieddate: 22-07-24
// Description: To show OOP implementation in Goa Legislative Assembly

using System;

public class Bill
{
    public enum BillStatus
    {
        Proposed,
        Pending,
        Approved,
        Rejected
    }

    private string title;
    private string description;
    private string proposer;
    private string dateIntroduced;
    private BillStatus status;

    public Bill(string title, string description, string proposer, string dateIntroduced, BillStatus status)
    {
        this.title = title;
        this.description = description;
        this.proposer = proposer;
        this.dateIntroduced = dateIntroduced;
        this.status = status;
    }

    public string Title
    {
        get { return title; }
    }

    public string Description
    {
        get { return description; }
    }

    public string Proposer
    {
        get { return proposer; }
    }

    public string DateIntroduced
    {
        get { return dateIntroduced; }
    }

    public BillStatus Status
    {
        get { return status; }
        set { status = value; }
    }

    public void DisplayInfo()
    {
        Console.WriteLine("Bill Title: " + title);
        Console.WriteLine("Description: " + description);
        Console.WriteLine("Proposer: " + proposer);
        Console.WriteLine("Date Introduced: " + dateIntroduced);
        Console.WriteLine("Status: " + status);
    }
}
