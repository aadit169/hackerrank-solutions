// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-oops/challenges/class-and-objects-cricket-team-management-system-1/problem?isFullScreen=true
// Problem     Class and Objects - Cricket Team Management System 1
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    java15
// Status      Accepted
// Submitted   2026-08-25, 04:16 p.m.
// ──────────────────────────────────────────────────

import java.io.*;
import java.util.*;


class Team{
    private String name;
    private String coach;
    private String location;
    private String players;
    private String captain;
    
    Team(){
        this.name=" ";
        this.coach=" ";
        this.location=" ";
        this.players=" ";
        this.captain=" ";
    }
    Team(String name, String coach, String location, String players, String captain ){
        this.name=name;
        this.coach=coach;
        this.location=location;
        this.players=players;
        this.captain=captain;
    }
    
    void displayDetails(){
        System.out.println("Team: "+this.name);
        System.out.println("Coach: "+this.coach);
        System.out.println("Location: "+this.location);
        System.out.println("Players: "+ this.players);
        System.out.println("Captain: "+ this.captain);
    }
    
}
public class Solution {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the team details");
        String input=sc.nextLine();
        String[] details=input.split("#");
        if (details.length==5){
            Team t=new Team(details[0], details[1], details[2], details[3], details[4]);
            t.displayDetails();
        }
        sc.close();        
    }
}
