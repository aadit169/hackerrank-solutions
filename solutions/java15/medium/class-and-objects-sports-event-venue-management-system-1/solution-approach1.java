// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-oops/challenges/class-and-objects-sports-event-venue-management-system-1/problem?isFullScreen=true
// Problem     Class and Objects - Sports Event Venue Management System 1
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    java15
// Status      Accepted
// Submitted   2026-08-19, 12:19 p.m.
// ──────────────────────────────────────────────────

import java.io.*;
import java.util.*;

class Venue{
    private String venue;
    private String city;
    
    Venue(String venue, String city){
        this.venue=venue;
        this.city=city;
    }
    void display(){
        System.out.println("Venue Details");
        System.out.println("Venue Name : "+this.venue);
        System.out.println("City Name : "+this.city);
        System.out.println(this.venue);
    }
}
public class Solution {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the venue name");
        String venue=sc.nextLine();
        System.out.println("Enter the city name");
        String city=sc.nextLine();
        Venue v=new Venue(venue, city);
        v.display();
        sc.close();
    }
    
}
