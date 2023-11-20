#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, sum=0;;
    cin >> n;
    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        sum+=ar[i];
    }

 
    sort(ar.rbegin(), ar.rend());

    int yourSum = 0;
    int coins = 0;

    for (int i = 0; i < n; i++) {
        yourSum += ar[i];
        coins++;
        if (yourSum > sum - yourSum) {
            break;
        }
    }

    cout << coins << endl;
    
    return 0;
}
