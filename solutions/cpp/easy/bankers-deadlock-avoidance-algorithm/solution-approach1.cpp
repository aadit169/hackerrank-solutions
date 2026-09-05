// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-os/challenges/bankers-deadlock-avoidance-algorithm/problem?isFullScreen=true
// Problem     Banker's Deadlock Avoidance Algorithm
// Difficulty  Easy
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-09-05, 08:33 p.m.
// ──────────────────────────────────────────────────

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;

    cout << "Enter number of processes: " << endl;
    if (!(cin >> n)) return 0;

    cout << "Enter number of resource types: " << endl;
    if (!(cin >> m)) return 0;

    int alloc[100][100];
    int max[100][100];
    int need[100][100];
    int avail[100];

    cout << "Enter Allocation Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> alloc[i][j];
        }
    }

    cout << "Enter Max Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> max[i][j];
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    cout << "Enter Available Resources: " << endl;
    for (int j = 0; j < m; j++) {
        cin >> avail[j];
    }

    int finish[100] = {0};
    int safeSeq[100];
    int count = 0;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int canRun = 1;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        canRun = 0;
                        break;
                    }
                }

                if (canRun) {
                    for (int j = 0; j < m; j++) {
                        avail[j] += alloc[i][j];
                    }
                    safeSeq[count++] = i;
                    finish[i] = 1;
                }
            }
        }
    }

    if (count == n) {
        cout << "System is in a SAFE STATE." << endl;
        cout << "Safe Sequence: ";
        for (int i = 0; i < n; i++) {
            cout << "P" << safeSeq[i] << " ";
        }
        cout << endl;
    } else {
        cout << "System is NOT in a safe state (Deadlock may occur)." << endl;
    }

    return 0;
}
