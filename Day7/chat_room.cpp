#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    string target = "hello";

    int i = 0; // Pointer for the input string
    int j = 0; // Pointer for the target string

    while (i < s.length() && j < target.length()) {
        if (s[i] == target[j]) {
            j++; // Move to the next character in the target string
        }
        i++; // Always move to the next character in the input string
    }

    // If we reached the end of the target string, it means "hello" can be formed.
    if (j == target.length()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
