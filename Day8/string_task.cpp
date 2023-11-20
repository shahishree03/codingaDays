#include<bits/stdc++.h> 
using namespace std;

int main()
{
    char vowels[] = {'a', 'A', 'e', 'E', 'o', 'O', 'U', 'u', 'I', 'i', 'Y', 'y'};
    string s;
    string c = "";
    cin >> s;
  

    for(int i = 0; i < s.size(); i++)
    {
        bool isVowel = false;

        for (int j = 0; j < 12; j++) {
            if (s[i] == vowels[j]) {
                isVowel = true;
                break;
            }
        }

        if (!isVowel)
        {
            c += ".";
            c += tolower(s[i]);
        }
    }

    cout << c;
}
