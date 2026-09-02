// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-os/challenges/priorityalgorithm/problem?isFullScreen=true
// Problem     Non-Preemptive Priority Scheduling algorithm
// Difficulty  Easy
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-09-02, 01:27 p.m.
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

struct Process {
    int id;
    int at;
    int bt;
    int priority;
    int ct;
    int tat;
    int wt;
};

int main() {
    int n;
    cout << "Enter number of processes: " << endl;
    if (!(cin >> n)) return 0;

    vector<Process> p(n);
    vector<bool> completed(n, false);

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cout << "Enter AT, BT and Priority for P" << (i + 1) << ": " << endl;
        cin >> p[i].at >> p[i].bt >> p[i].priority;
    }

    int current_time = 0;
    int completed_count = 0;
    float total_tat = 0, total_wt = 0;

    while (completed_count < n) {
        int idx = -1;
        int highest_priority = 1e9;

        for (int i = 0; i < n; i++) {
            if (!completed[i] && p[i].at <= current_time) {
                if (p[i].priority < highest_priority) {
                    highest_priority = p[i].priority;
                    idx = i;
                } else if (p[i].priority == highest_priority) {
                    if (idx != -1 && p[i].at < p[idx].at) {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            current_time += p[idx].bt;
            p[idx].ct = current_time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;

            total_tat += p[idx].tat;
            total_wt += p[idx].wt;

            completed[idx] = true;
            completed_count++;
        } else {
            int min_at = 1e9;
            for (int i = 0; i < n; i++) {
                if (!completed[i] && p[i].at < min_at) {
                    min_at = p[i].at;
                }
            }
            current_time = min_at;
        }
    }

    cout << fixed << setprecision(2);
    cout << "Average Turnaround Time = " << (total_tat / n) << endl;
    cout << "Average Waiting Time = " << (total_wt / n) << endl;

    return 0;
}
