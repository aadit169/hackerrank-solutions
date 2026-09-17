// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/product-inventory-search-in-a-warehouse/problem?isFullScreen=true
// Problem     Searching: Product Inventory Search in a Warehouse
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-09-17, 01:26 p.m.
// ──────────────────────────────────────────────────

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


#include <iostream>
using namespace std;

int main() {
    int m, n;
    if (!(cin >> m >> n)) return 0;

    int arr[100][100];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int target;
    cin >> target;

    int low = 0;
    int high = m * n - 1;
    bool found = false;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int r = mid / n;
        int c = mid % n;

        if (arr[r][c] == target) {
            found = true;
            break;
        } else if (arr[r][c] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (found) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
