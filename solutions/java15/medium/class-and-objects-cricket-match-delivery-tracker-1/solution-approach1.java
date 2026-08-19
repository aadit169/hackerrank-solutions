// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-oops/challenges/class-and-objects-cricket-match-delivery-tracker-1/problem?isFullScreen=true
// Problem     Class and Objects - Cricket Match Delivery Tracker 1
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    java15
// Status      Accepted
// Submitted   2026-08-19, 12:51 p.m.
// ──────────────────────────────────────────────────

import java.io.*;
import java.util.*;


class Delivery{
    private long Over;
    private long Ball;
    private long Runs;
    private String Batsman;
    private String Bowler;
    private String NonStriker;
    
    
    Delivery(long Over, long Ball, long Runs, String Batsman, String Bowler, String NonStriker){
        this.Over=Over;
        this.Ball=Ball;
        this.Runs=Runs;
        this.Batsman=Batsman;
        this.Bowler=Bowler;
        this.NonStriker=NonStriker;
    }
    void displayDeliveryDetails(){
        System.out.println("Delivery Details : ");
        System.out.println("Over : "+this.Over);
        System.out.println("Ball : "+this.Ball);
        System.out.println("Runs : "+this.Runs);
        System.out.println("Batsman : "+this.Batsman);
        System.out.println("Bowler : "+this.Bowler);
        System.out.println("NonStriker : "+this.NonStriker);
    }
}
public class Solution {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the over");
        long Over=sc.nextLong();
        
        System.out.println("Enter the ball");
        long Ball=sc.nextLong();
        
        System.out.println("Enter the runs");
        long Runs=sc.nextLong();
       sc.nextLine();
        System.out.println("Enter the batsman name");
        String Batsman=sc.nextLine();
        
        System.out.println("Enter the bowler name");
        String Bowler=sc.nextLine();
        
        System.out.println("Enter the nonStriker name");
        String NonStriker=sc.nextLine();
        
        Delivery d=new Delivery(Over, Ball, Runs, Batsman, Bowler, NonStriker);
        d.displayDeliveryDetails();
        sc.close();
    }
    
}
