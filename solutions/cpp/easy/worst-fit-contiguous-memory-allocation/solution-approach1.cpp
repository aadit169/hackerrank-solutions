// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-os/challenges/worst-fit-contiguous-memory-allocation/problem?isFullScreen=true
// Problem     Worst Fit Contiguous Memory Allocation
// Difficulty  Easy
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-09-08, 01:41 p.m.
// ──────────────────────────────────────────────────

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int m;
    cout << "Enter number of memory blocks: " << endl;
    if (!(cin >> m)) return 0;

    int* originalBlockSize = new int[m];
    bool* isAllocated = new bool[m];

    cout << "Enter size of each block: " << endl;
    for (int i = 0; i < m; i++) {
        cin >> originalBlockSize[i];
        isAllocated[i] = false;
    }

    int n;
    cout << "Enter number of processes: " << endl;
    if (!(cin >> n)) return 0;

    int* processSize = new int[n];
    cout << "Enter size of each process: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> processSize[i];
    }

    for (int i = 0; i < n; i++) {
        int worstBlock = -1;

        for (int j = 0; j < m; j++) {
            if (!isAllocated[j] && originalBlockSize[j] >= processSize[i]) {
                if (worstBlock == -1 || originalBlockSize[j] > originalBlockSize[worstBlock]) {
                    worstBlock = j;
                }
            }
        }

        if (worstBlock != -1) {
            isAllocated[worstBlock] = true;
            int fragment = originalBlockSize[worstBlock] - processSize[i];
            cout << "Process " << (i + 1) << " of size " << processSize[i]
                 << " is allocated to Block " << (worstBlock + 1)
                 << " of size " << originalBlockSize[worstBlock]
                 << " with Fragment " << fragment << endl;
        } else {
            cout << "Process " << (i + 1) << " of size " << processSize[i]
                 << " is not allocated" << endl;
        }
    }

    delete[] originalBlockSize;
    delete[] isAllocated;
    delete[] processSize;

    return 0;
}
