// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-os/challenges/fifo-page-replacement-algorithm-1/problem?isFullScreen=true
// Problem     FIFO Page Replacement Algorithm
// Difficulty  Easy
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-09-05, 08:36 p.m.
// ──────────────────────────────────────────────────

#include <iostream>

using namespace std;

int main()
{
    int pages[100], frames[100];
    int n, capacity;
    int i, j;
    int faults = 0;
    int hits = 0;
    int front = 0;
    int found;

    cout << "Enter number of pages in reference string: " << endl;
    if (!(cin >> n)) return 0;

    cout << "Enter the reference string: " << endl;
    for(i = 0; i < n; i++)
        cin >> pages[i];

    cout << "Enter number of frames: " << endl;
    cin >> capacity;

    for(i = 0; i < capacity; i++)
        frames[i] = -1;

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < capacity; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if(found)
        {
            hits++;
        }
        else
        {
            frames[front] = pages[i];
            front = (front + 1) % capacity;
            faults++;
        }
    }

    cout << "Total Page Faults: " << faults << endl;
    cout << "Total Page Hits: " << hits << endl;

    return 0;
}
