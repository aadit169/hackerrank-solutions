// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-os/challenges/first-fit-contiguous-memory-allocation/problem?isFullScreen=true
// Problem     First Fit Contiguous Memory Allocation
// Difficulty  Easy
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-09-08, 01:35 p.m.
// ──────────────────────────────────────────────────

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


using namespace std;

int main() {
    int m;
    cout << "Enter number of memory blocks: " << endl;
    if (!(cin >> m)) return 0;

    int* originalBlockSize = new int[m];
    int* remainingBlockSize = new int[m];

    cout << "Enter size of each block: " << endl;
    for (int i = 0; i < m; i++) {
        cin >> originalBlockSize[i];
        remainingBlockSize[i] = originalBlockSize[i];
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
        int allocatedBlock = -1;
        for (int j = 0; j < m; j++) {
            if (remainingBlockSize[j] >= processSize[i]) {
                allocatedBlock = j;
                break;
            }
        }

        if (allocatedBlock != -1) {
            remainingBlockSize[allocatedBlock] -= processSize[i];
            cout << "Process " << (i + 1) << " of size " << processSize[i]
                 << " is allocated to Block " << (allocatedBlock + 1)
                 << " of size " << originalBlockSize[allocatedBlock]
                 << " with Fragment " << remainingBlockSize[allocatedBlock] << endl;
        } else {
            cout << "Process " << (i + 1) << " of size " << processSize[i]
                 << " is not allocated" << endl;
        }
    }

    delete[] originalBlockSize;
    delete[] remainingBlockSize;
    delete[] processSize;

    return 0;
}
