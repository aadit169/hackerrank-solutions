// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-os/challenges/optimal-page-replacement-algorithm-1/problem?isFullScreen=true
// Problem     Optimal Page Replacement Algorithm
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-09-08, 01:33 p.m.
// ──────────────────────────────────────────────────

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


using namespace std;

int findOptimal(int pages[], int frames[], int no_of_pages, int index, int no_of_frames) {
    int res = -1;
    int farthest = index;

    for (int i = 0; i < no_of_frames; i++) {
        int j;
        for (j = index; j < no_of_pages; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }

        if (j == no_of_pages) {
            return i;
        }
    }

    if (res == -1) {
        return 0;
    }
    return res;
}

int main() {
    int no_of_pages;
    cout << "Enter number of pages in reference string: " << endl;
    if (!(cin >> no_of_pages)) return 0;

    int* pages = new int[no_of_pages];
    cout << "Enter the reference string: " << endl;
    for (int i = 0; i < no_of_pages; i++) {
        cin >> pages[i];
    }

    int no_of_frames;
    cout << "Enter number of frames: " << endl;
    if (!(cin >> no_of_frames)) return 0;

    int* frames = new int[no_of_frames];
    for (int i = 0; i < no_of_frames; i++) {
        frames[i] = -1;
    }

    int faults = 0;
    int hits = 0;

    for (int i = 0; i < no_of_pages; i++) {
        int hit = 0;

        for (int j = 0; j < no_of_frames; j++) {
            if (frames[j] == pages[i]) {
                hit = 1;
                hits++;
                break;
            }
        }

        if (!hit) {
            faults++;
            int empty_found = 0;

            for (int j = 0; j < no_of_frames; j++) {
                if (frames[j] == -1) {
                    frames[j] = pages[i];
                    empty_found = 1;
                    break;
                }
            }

            if (!empty_found) {
                int pos = findOptimal(pages, frames, no_of_pages, i + 1, no_of_frames);
                frames[pos] = pages[i];
            }
        }
    }

    cout << "Total Page Faults: " << faults << endl;
    cout << "Total Page Hits: " << hits << endl;

    delete[] pages;
    delete[] frames;

    return 0;
}
