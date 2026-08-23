// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-oops/challenges/class-and-objects-sports-venue-information-system-1/problem?isFullScreen=true
// Problem     Class and Objects - Sports Venue Information System 1
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    java15
// Status      Accepted
// Submitted   2026-08-23, 03:27 p.m.
// ──────────────────────────────────────────────────

import java.io.*;
import java.util.*;

class Venue {
    private String name;
    private String city;
    
    Venue(String name, String city) {
        this.name = name;
        this.city = city;
    }
    void displayVenueDetails() {
        System.out.println("Venue Details ");
        System.out.println("Venue Name : " + name);
        System.out.println("City Name : " + city);
    }
}
public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the venue details");
        String input = sc.nextLine();
        String[] details = input.split(",");
        Venue venue = new Venue(details[0].trim(), details[1].trim());
        venue.displayVenueDetails();
        sc.close();
    }
}
