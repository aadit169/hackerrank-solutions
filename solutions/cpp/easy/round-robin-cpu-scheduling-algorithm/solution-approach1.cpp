// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-os/challenges/round-robin-cpu-scheduling-algorithm/problem?isFullScreen=true
// Problem     Round Robin CPU Scheduling Algorithm
// Difficulty  Easy
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-09-03, 09:39 a.m.
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
    int rem_bt;
    int ct;
    int tat;
    int wt;
};

int main() {
    int n, tq;
    cout << "Enter number of processes: " << endl;
    if (!(cin >> n)) return 0;

    cout << "Enter Time Quantum: " << endl;
    if (!(cin >> tq)) return 0;

    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cout << "Enter AT and BT for P" << (i + 1) << ": " << endl;
        cin >> p[i].at >> p[i].bt;
        p[i].rem_bt = p[i].bt;
    }

    queue<int> q;
    vector<bool> in_queue(n, false);
    int current_time = 0;
    int completed = 0;

    auto push_arrived = [&](int time_limit) {
        for (int i = 0; i < n; i++) {
            if (!in_queue[i] && p[i].at <= time_limit && p[i].rem_bt > 0) {
                q.push(i);
                in_queue[i] = true;
            }
        }
    };

    push_arrived(current_time);

    while (completed < n) {
        if (q.empty()) {
            int next_at = 1e9;
            for (int i = 0; i < n; i++) {
                if (p[i].rem_bt > 0 && p[i].at < next_at) {
                    next_at = p[i].at;
                }
            }
            current_time = next_at;
            push_arrived(current_time);
            continue;
        }

        int idx = q.front();
        q.pop();

        int exec_time = min(tq, p[idx].rem_bt);
        current_time += exec_time;
        p[idx].rem_bt -= exec_time;

        push_arrived(current_time);

        if (p[idx].rem_bt > 0) {
            q.push(idx);
        } else {
            p[idx].ct = current_time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            completed++;
        }
    }

    float total_tat = 0, total_wt = 0;
    for (int i = 0; i < n; i++) {
        total_tat += p[i].tat;
        total_wt += p[i].wt;
    }

    cout << fixed << setprecision(2);
    cout << "Average Turnaround Time: " << (total_tat / n) << endl;
    cout << "Average Waiting Time: " << (total_wt / n) << endl;

    return 0;
}
