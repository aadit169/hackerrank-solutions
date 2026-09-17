// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/linear-search-in-a-library/problem?isFullScreen=true
// Problem     Searching: Linear Search in a Library
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-09-17, 01:23 p.m.
// ──────────────────────────────────────────────────

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    if (!(cin >> n)) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
