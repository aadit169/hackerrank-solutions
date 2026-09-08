// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-os/challenges/lru-page-replacement-algorithm-1/problem?isFullScreen=true
// Problem     LRU Page Replacement Algorithm
// Difficulty  Easy
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-09-08, 01:31 p.m.
// ──────────────────────────────────────────────────

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int findLRU(int time[], int n) {
    int minimum = time[0], pos = 0;
    for (int i = 1; i < n; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int no_of_pages;
    cout << "Enter number of pages in reference string: " << endl;
    if (!(cin >> no_of_pages)) return 0;

    int pages[100];
    cout << "Enter the reference string: " << endl;
    for (int i = 0; i < no_of_pages; ++i) {
        cin >> pages[i];
    }

    int no_of_frames;
    cout << "Enter number of frames: " << endl;
    if (!(cin >> no_of_frames)) return 0;

    int frames[20];
    int time[20];

    for (int i = 0; i < no_of_frames; ++i) {
        frames[i] = -1;
        time[i] = 0;
    }

    int faults = 0, hits = 0, counter = 0;

    for (int i = 0; i < no_of_pages; ++i) {
        bool hit = false;
        for (int j = 0; j < no_of_frames; ++j) {
            if (frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                hit = true;
                hits++;
                break;
            }
        }

        if (!hit) {
            bool emptySlot = false;
            for (int j = 0; j < no_of_frames; ++j) {
                if (frames[j] == -1) {
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    emptySlot = true;
                    break;
                }
            }

            if (!emptySlot) {
                int pos = findLRU(time, no_of_frames);
                counter++;
                faults++;
                frames[pos] = pages[i];
                time[pos] = counter;
            }
        }
    }

    cout << "Total Page Faults: " << faults << endl;
    cout << "Total Page Hits: " << hits << endl;

    return 0;
}
