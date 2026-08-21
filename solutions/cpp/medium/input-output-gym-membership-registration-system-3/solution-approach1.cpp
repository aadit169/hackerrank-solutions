// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-dsa-beginner/challenges/input-output-gym-membership-registration-system-3/problem?isFullScreen=true
// Problem     Input & Output - Gym Membership Registration System
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-08-21, 09:18 p.m.
// ──────────────────────────────────────────────────

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string name;
    string mem;
    getline(cin, name);
    getline(cin, mem);
    cout<<"Member Name: "<<name<<endl;
    cout<<"Selected Membership: "<<mem;
    return 0;
}
