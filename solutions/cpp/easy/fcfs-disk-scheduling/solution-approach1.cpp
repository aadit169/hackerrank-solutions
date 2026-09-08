// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-os/challenges/fcfs-disk-scheduling/problem?isFullScreen=true
// Problem     FCFS Disk Scheduling
// Difficulty  Easy
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-09-08, 01:48 p.m.
// ──────────────────────────────────────────────────

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int head;
    cout << "Enter the initial head position: " << endl;
    if (!(cin >> head)) return 0;

    int n;
    cout << "Enter the number of disk requests: " << endl;
    if (!(cin >> n)) return 0;

    int* requests = new int[n];
    cout << "Enter the disk request sequence: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> requests[i];
    }

    int totalHeadMovement = 0;

    for (int i = 0; i < n; i++) {
        totalHeadMovement += abs(head - requests[i]);
        head = requests[i];
    }

    cout << "Total Head Movement = " << totalHeadMovement << endl;

    delete[] requests;

    return 0;
}
