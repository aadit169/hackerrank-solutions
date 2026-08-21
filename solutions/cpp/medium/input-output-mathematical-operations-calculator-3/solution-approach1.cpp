// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-dsa-beginner/challenges/input-output-mathematical-operations-calculator-3/problem?isFullScreen=true
// Problem     Input & Output - Mathematical Operations Calculator
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-08-21, 09:36 p.m.
// ──────────────────────────────────────────────────

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    double num1, num2;
    cin >> num1 >> num2;

    cout << fixed << setprecision(1);
    cout << "Square Root of first number: " << sqrt(num1) << endl;
    cout << "First number raised to the power of second number: " << pow(num1, num2) << endl;
    cout << "Absolute value of first number: " << fabs(num1) << endl;
    cout << "Absolute value of second number: " << fabs(num2) << endl;
    return 0;
}
