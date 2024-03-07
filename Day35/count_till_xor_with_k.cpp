#include<bits/stdc++.h>
using namespace std;
int subarraysWithSumK(vector < int > a, int b) {
   int xr=0;
    unordered_map<int, int> mp;
    mp[xr]++;
    int count=0;
    for(int i=0;i<a.size();i++)
    {
        xr=xr^a[i];
        int x= xr^b;
        count+=mp[x];
        mp[xr]++;
    }
    return count;
}
