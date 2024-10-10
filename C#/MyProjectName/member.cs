// Author: Clayton
// Rollno: 31
// Title: Goa Legislative Assembly
// Startdate: 15-07-24
// Modifieddate: 22-07-24
// Description: To show OOP implementation in Goa Legislative Assembly

using System;

public class Member
{
    private string name;
    private int age;
    private string constituency;
    private string party;
    private string position;

    public Member(string name, int age, string constituency, string party, string position)
    {
        this.name = name;
        this.age = age;
        this.constituency = constituency;
        this.party = party;
        this.position = position;
    }

    public string Name
    {
        get { return name; }
    }

    public int Age
    {
        get { return age; }
        set { age = value; }
    }

    public string Constituency
    {
        get { return constituency; }
    }

    public string Party
    {
        get { return party; }
        set { party = value; }
    }

    public string Position
    {
        get { return position; }
        set { position = value; }
    }

    public void DisplayInfo()
    {
        Console.WriteLine("Name: " + name);
        Console.WriteLine("Age: " + age);
        Console.WriteLine("Constituency: " + constituency);
        Console.WriteLine("Party: " + party);
        Console.WriteLine("Position: " + position);
    }
}
