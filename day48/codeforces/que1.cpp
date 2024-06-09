#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int n, m;
        cin >> n >> m; // Read n and m in the same line

        char arr[n + 1]; // Allocate space for the null terminator
        cin >> arr;

        int count = 0;
        unordered_map<char, int> l;
        for (char c = 'A'; c <= 'G'; c++) {
            l[c] = 0;
        }
        for (char c : arr) {
            l[c]++;
        }
        for (char c = 'A'; c <= 'G'; c++) {
            if (l[c] < m) {
                count += (m - l[c]);
            }
        }
        cout << count << endl; // Output using cout for consistency
    }
    return 0;
}
