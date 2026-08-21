// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-oops/challenges/class-and-objects-cricket-player-information-tracker-1/problem?isFullScreen=true
// Problem     Class and Objects - Cricket Player Information Tracker 1
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    java15
// Status      Accepted
// Submitted   2026-08-21, 01:45 p.m.
// ──────────────────────────────────────────────────

import java.io.*;
import java.util.*;

class Player {
    private String name;
    private String country;
    private String skill;

    Player(String name, String country, String skill) {
        this.name = name;
        this.country = country;
        this.skill = skill;
    }

    void displayPlayerDetails() {
        System.out.println("Player Details");
        System.out.println("Player Name : " + name);
        System.out.println("Country Name : " + country);
        System.out.println("Skill : " + skill);
    }
}

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the player details");
        String input = sc.nextLine();
        
        String[] details = input.split(",");
        
        Player player = new Player(details[0].trim(), details[1].trim(), details[2].trim());
        player.displayPlayerDetails();
        
        sc.close();
    }
}
