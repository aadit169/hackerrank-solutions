// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-os/challenges/round-robin-cpu-scheduling-algorithm/problem?isFullScreen=true
// Problem     Round Robin CPU Scheduling Algorithm
// Difficulty  Easy
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-09-03, 09:42 a.m.
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
#include <iomanip>

using namespace std;

int main() {
    int n, tq;
    cout << "Enter number of processes: " << endl;
    if (!(cin >> n)) return 0;

    cout << "Enter Time Quantum: " << endl;
    if (!(cin >> tq)) return 0;

    int at[100], bt[100], rem[100];
    int ct[100], tat[100], wt[100];

    for (int i = 0; i < n; i++) {
        cout << "Enter AT and BT for P" << (i + 1) << ": " << endl;
        cin >> at[i] >> bt[i];
        rem[i] = bt[i];
    }

    int q[1000];
    int front = 0, rear = 0;
    int visited[100] = {0};

    int time = 0;
    int done = 0;

    for (int i = 0; i < n; i++) {
        if (at[i] <= time && !visited[i]) {
            q[rear++] = i;
            visited[i] = 1;
        }
    }

    while (done < n) {
        if (front == rear) {
            int next_at = 1e9;
            for (int i = 0; i < n; i++) {
                if (rem[i] > 0 && at[i] < next_at) {
                    next_at = at[i];
                }
            }
            time = next_at;
            for (int i = 0; i < n; i++) {
                if (at[i] <= time && !visited[i] && rem[i] > 0) {
                    q[rear++] = i;
                    visited[i] = 1;
                }
            }
        }

        int curr = q[front++];

        int run = (rem[curr] > tq) ? tq : rem[curr];
        time += run;
        rem[curr] -= run;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && !visited[i] && rem[i] > 0) {
                q[rear++] = i;
                visited[i] = 1;
            }
        }

        if (rem[curr] > 0) {
            q[rear++] = curr;
        } else {
            ct[curr] = time;
            tat[curr] = ct[curr] - at[curr];
            wt[curr] = tat[curr] - bt[curr];
            done++;
        }
    }

    float sum_tat = 0, sum_wt = 0;
    for (int i = 0; i < n; i++) {
        sum_tat += tat[i];
        sum_wt += wt[i];
    }

    cout << fixed << setprecision(2);
    cout << "Average Turnaround Time: " << (sum_tat / n) << endl;
    cout << "Average Waiting Time: " << (sum_wt / n) << endl;

    return 0;
}
