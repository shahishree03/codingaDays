#include<iostream>
#include<vector> 
#include<map>
using namespace std;

int getLongest(vector<int>& arr, int k)
{
    int n =arr.size();
    map<int, int> mp;
    int sum =0;
    int maxLen =0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==k)
        {
            maxLen = max(maxLen, i+1);
        }
        int rem =sum - k;
        if(mp.find(rem)!=mp.end())
        {
          int length = i-mp[rem];
          maxLen = max(maxLen, length);
        }
        if(mp.find(rem)==mp.end())
        {
            mp[rem]=i;
        }
        
    }
    return maxLen;
}
int main()
{
    vector<int> arr = {-1,1,-1};
int k = 1;
    int len = getLongest(arr, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
