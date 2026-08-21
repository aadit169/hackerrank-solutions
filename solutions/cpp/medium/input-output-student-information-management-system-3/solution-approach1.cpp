// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-dsa-beginner/challenges/input-output-student-information-management-system-3/problem?isFullScreen=true
// Problem     Input & Output - Student Information Management System
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-08-21, 09:07 p.m.
// ──────────────────────────────────────────────────

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    string name;
    int age;
    float cgpa;
    char grade;

    cin >> name;
    cin >> age;
    cin >> cgpa;
    cin >> grade;
    cgpa = ((int)(cgpa * 100)) / 100.0f;

    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "CGPA: " << fixed << setprecision(2) << cgpa << endl;
    cout << "Grade: " << grade << endl;

    return 0;
}
