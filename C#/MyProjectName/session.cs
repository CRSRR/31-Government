// Author: Clayton
// Rollno: 31
// Title: Goa Legislative Assembly
// Startdate: 15-07-24
// Modifieddate: 22-07-24
// Description: To show OOP implementation in Goa Legislative Assembly

using System;
using System.Collections.Generic;

public class Session
{
    private string sessionDate;
    private int startHour;
    private int startMinute;
    private int endHour;
    private int endMinute;
    private string agenda;
    private List<string> topicsOfDiscussion;

    public Session(string sessionDate, int startHour, int startMinute, int endHour, int endMinute, string agenda)
    {
        this.sessionDate = sessionDate;
        SetStartHour(startHour);
        SetStartMinute(startMinute);
        SetEndHour(endHour);
        SetEndMinute(endMinute);
        this.agenda = agenda;
        this.topicsOfDiscussion = new List<string>();
    }

    public void SetStartHour(int startHour)
    {
        if (startHour < 0 || startHour > 23)
        {
            throw new ArgumentException("Hour must be between 0 and 23.");
        }
        this.startHour = startHour;
    }

    public void SetStartMinute(int startMinute)
    {
        if (startMinute < 0 || startMinute > 59)
        {
            throw new ArgumentException("Minute must be between 0 and 59.");
        }
        this.startMinute = startMinute;
    }

    public void SetEndHour(int endHour)
    {
        if (endHour < 0 || endHour > 23)
        {
            throw new ArgumentException("Hour must be between 0 and 23.");
        }
        this.endHour = endHour;
    }

    public void SetEndMinute(int endMinute)
    {
        if (endMinute < 0 || endMinute > 59)
        {
            throw new ArgumentException("Minute must be between 0 and 59.");
        }
        this.endMinute = endMinute;
    }

    public void AddTopicOfDiscussion(string topic)
    {
        topicsOfDiscussion.Add(topic);
    }

    public string Agenda
    {
        get { return agenda; }
    }

    public void DisplayInfo()
    {
        Console.WriteLine("Session Date: " + sessionDate);
        Console.WriteLine($"Start Time: {startHour:D2}:{startMinute:D2}");
        Console.WriteLine($"End Time: {endHour:D2}:{endMinute:D2}");
        Console.WriteLine("Agenda: " + agenda);
        Console.WriteLine("Topics of Discussion:");
        foreach (string topic in topicsOfDiscussion)
        {
            Console.WriteLine(" - " + topic);
        }
    }
}
