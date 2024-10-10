using System;
using System.Collections.Generic;

public class Legis
{
    private static List<Member> members = new();
    private static List<Bill> bills = new();
    private static List<Session> sessions = new();
    private static List<Constituency> constituencies = new();

    public static void Main()
    {
        while (true)
        {
            Console.WriteLine("1. Add Member 2. View Members 3. Add Bill 4. Create Session 5. See Sessions 6. View Constituencies 0. EXIT");
            if (!int.TryParse(Console.ReadLine(), out int choice)) continue;
                switch (choice)
            {
                case 1:
                    AddMember();
                    break;
                case 2:
                   DisplayList(members, m => m.DisplayInfo());
                    break;
                case 3:
                    AddBill();
                    break;
                case 4:
                    CreateSession();
                    break;
                case 5:
                    DisplayList(sessions, s => Console.WriteLine(s.Agenda));
                    break;
                case 6:
                    DisplayList(constituencies, c => Console.WriteLine(c.Name));
                    break;
                case 0:
                    Console.WriteLine("Exiting the program. Thank you!");
                    Environment.Exit(0);
                    break;
                default:
                    Console.WriteLine("Invalid choice. Please try again.");
                    break;
            }
        }
    }

    private static void AddMember()
    {
        var member = new Member(
            GetInput("Enter member name: "),
            GetIntInput("Enter age: "),
            GetInput("Enter constituency: "),
            GetInput("Enter party: "),
            GetInput("Enter position: ")
        );
        members.Add(member);

        var constituency = constituencies.Find(c => c.Name == member.Constituency) ?? new Constituency(member.Constituency);
        if (!constituencies.Contains(constituency)) constituencies.Add(constituency);
        constituency.AddMember(member);
    }

    private static void AddBill()
    {
        bills.Add(new Bill(
            GetInput("Enter bill title: "),
            GetInput("Enter bill description: "),
            GetInput("Enter proposer: "),
            GetInput("Enter date introduced (DD-MM-YYYY): "),
            Enum.TryParse(GetInput("Enter status (Proposed, Pending, Approved, Rejected): "), true, out Bill.BillStatus status) ? status : Bill.BillStatus.Proposed
        ));
    }

    private static void CreateSession()
    {
        var session = new Session(
            GetInput("Enter session date (dd/MM/yyyy): "),
            GetIntInput("Enter start hour (0-23): "),
            GetIntInput("Enter start minute (0-59): "),
            GetIntInput("Enter end hour (0-23): "),
            GetIntInput("Enter end minute (0-59): "),
            GetInput("Enter agenda: ")
        );
        sessions.Add(session);

        while (GetInput("Add a topic? (yes/no): ").ToLower() == "yes")
            session.AddTopicOfDiscussion(GetInput("Enter topic: "));
    }

    private static string GetInput(string prompt)
    {
        Console.Write(prompt);
        return Console.ReadLine() ?? string.Empty;
    }

    private static int GetIntInput(string prompt)
    {
        Console.Write(prompt);
        return int.TryParse(Console.ReadLine(), out int value) ? value : 0;
    }

    private static void DisplayList<T>(List<T> list, Action<T> displayAction)
    {
        list.ForEach(displayAction);
    }
}
