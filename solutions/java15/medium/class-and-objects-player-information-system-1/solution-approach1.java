// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-oops/challenges/class-and-objects-player-information-system-1/problem?isFullScreen=true
// Problem     Class and Objects - Player Information System 1
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    java15
// Status      Accepted
// Submitted   2026-08-19, 08:44 a.m.
// ──────────────────────────────────────────────────

import java.io.*;
import java.util.*;

class Player{
    private String name;
    private String country;
    private String skill;
    
    Player(String name, String country, String skill){
        this.name=name;
        this.country=country;
        this.skill=skill;
    }
    void display(){
        System.out.println("Player Details:");
        System.out.println("Player Name : "+this.name);
        System.out.println("Country Name : "+this.country);
        System.out.println("Skill : "+this.skill);
    }
}
public class Solution {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the player name");
        String name=sc.nextLine();
        System.out.println("Enter the country name");
        String country=sc.nextLine();
        System.out.println("Enter the skill");
        String skill=sc.nextLine();
        Player p=new Player(name, country, skill);
        p.display();
        sc.close();
    }
}
