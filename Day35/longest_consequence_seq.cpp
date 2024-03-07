#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
  if (n == 0) return 0;

    int longest = 1;
  set<int> nums;
  for(int i=0;i<n;i++)
  {
      nums.insert(arr[i]);
  }
  for(auto i:nums)
  {
      if(nums.find(i-1)==nums.end())
      {
          //
          int cnt=1;
          int x=i;
          while(nums.find(x+1)!=nums.end())
          {
              x=x+1;
              cnt++;
          }
          longest = max(longest, cnt);
      }
  }
  return longest;
}
