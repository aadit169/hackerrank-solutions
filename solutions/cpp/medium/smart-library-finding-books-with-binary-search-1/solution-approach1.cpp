// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/smart-library-finding-books-with-binary-search-1/problem?isFullScreen=true
// Problem     Searching: Finding Books with Binary Search
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-09-17, 01:24 p.m.
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
    int n;
    if (!(cin >> n)) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            ans = mid;
            break;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
