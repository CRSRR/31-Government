//Author:Clayton
//Rollno:31
//Title:Goa Legislative Assembly
//Startdate:15-07-24
//Modifieddate:22-07-24
//Description:to show oop implementation in goa legislative assembly
import java.util.ArrayList;
import java.util.List;

public class Session {
    private String sessionDate; 
    private int startHour; 
    private int startMinute; 
    private int endHour; 
    private int endMinute; 
    private String agenda;
    private List<String> topicsOfDiscussion;

    public Session(String sessionDate, int startHour, int startMinute, int endHour, int endMinute, String agenda) {
        this.sessionDate = sessionDate;
        setStartHour(startHour); 
        setStartMinute(startMinute); 
        setEndHour(endHour); 
        setEndMinute(endMinute); 
        this.agenda = agenda;
        this.topicsOfDiscussion = new ArrayList<>();
    }

    public void setStartHour(int startHour) {
        if (startHour < 0 || startHour > 23) {
            throw new IllegalArgumentException("hour between 0-23.");
        }
        this.startHour = startHour;
    }

    public void setStartMinute(int startMinute) {
        if (startMinute < 0 || startMinute > 59) {
            throw new IllegalArgumentException("minute between 0-59.");
        }
        this.startMinute = startMinute;
    }

    public void setEndHour(int endHour) {
        if (endHour < 0 || endHour > 23) {
            throw new IllegalArgumentException("hour between 0-23.");
        }
        this.endHour = endHour;
    }

    public void setEndMinute(int endMinute) {
        if (endMinute < 0 || endMinute > 59) {
            throw new IllegalArgumentException("minute between 0-59.");
        }
        this.endMinute = endMinute;
    }

    public void addTopicOfDiscussion(String topic) {
        topicsOfDiscussion.add(topic);
    }

    public String getAgenda() {
        return agenda;
    }

    public void displayInfo() {
        System.out.println("Session Date: " + sessionDate);
        System.out.printf("Start Time: %02d:%02d\n", startHour, startMinute);
        System.out.printf("End Time: %02d:%02d\n", endHour, endMinute);
        System.out.println("Agenda: " + agenda);
        System.out.println("Topics of Discussion:");
        for (String topic : topicsOfDiscussion) {
            System.out.println(" - " + topic);
        }
    }
}
