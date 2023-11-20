#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int c0 = 0, c1 = 0;
    int length = s.size();

    for (int i = 0; i < length; i++) {
        if (s[i] == '0') {
            c0++;
            c1 = 0; // Reset the count for '1'
        } else {
            c1++;
            c0 = 0; // Reset the count for '0'
        }

        if (c0 >= 7 || c1 >= 7) {
            cout << "YES";
            return 0; // Exit the program, no need to check further
        }
    }

    cout << "NO"; // If no dangerous situation found
    return 0;
}
