// Author: Clayton
// Rollno: 31
// Title: Goa Legislative Assembly
// Startdate: 15-07-24
// Modifieddate: 22-07-24
// Description: To show OOP implementation in Goa Legislative Assembly

using System;
using System.Collections.Generic;

public class Constituency
{
    private string name;
    private List<Member> members;

    public Constituency(string name)
    {
        this.name = name;
        this.members = new List<Member>();
    }

    public string Name
    {
        get { return name; }
    }

    public void AddMember(Member member)
    {
        members.Add(member);
    }

    public void DisplayInfo()
    {
        Console.WriteLine("Constituency: " + name);
        Console.WriteLine("Members:");
        foreach (var member in members)
        {
            member.DisplayInfo();
        }
    }
}
