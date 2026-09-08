// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-os/challenges/sstf-disk-scheduling/problem?isFullScreen=true
// Problem     SSTF Disk Scheduling
// Difficulty  Easy
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-09-08, 01:43 p.m.
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
    bool* serviced = new bool[n];

    cout << "Enter the disk request sequence: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> requests[i];
        serviced[i] = false;
    }

    int totalHeadMovement = 0;

    for (int i = 0; i < n; i++) {
        int minDistance = -1;
        int closestIndex = -1;

        for (int j = 0; j < n; j++) {
            if (!serviced[j]) {
                int distance = abs(head - requests[j]);
                if (minDistance == -1 || distance < minDistance) {
                    minDistance = distance;
                    closestIndex = j;
                }
            }
        }

        serviced[closestIndex] = true;
        totalHeadMovement += minDistance;
        head = requests[closestIndex];
    }

    cout << "Total Head Movement = " << totalHeadMovement << endl;

    delete[] requests;
    delete[] serviced;

    return 0;
}
