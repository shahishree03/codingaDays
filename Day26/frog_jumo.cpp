#include<iostream>
using namespace std;
//recursion
f(int ind)
{
if(ind==0) return 0;
min_steps=INT_MAX;
  for(j=1;j<=k;j++)
    {
    if((ind-j)>0) 
jump=f(ind-j)+abs(a[ind-a[ind-j])
  min_steps=min(min_steps, jump);
    }
  return min_steps;
}
//memoziation
f1(vector<int>& a, vector<int>& dp , int ind, int k)
{
  if(ind==0) return 0;
  if(dp[ind]!=-1) return dp[ind];
//  dp[0]=0;
  for(int i=1;i<n;i++)
    {
min_steps=INT_MAX;
      for(int j=1;j<=k;j++)
        {
if(i-j>=0)
{

jump=dp[i-j]+abs(a[ind]-a[ind-j]);
  min_steps=min(min_steps,jump);
}
        }
      return dp[ind]=min_steps;
    }
}



f2(vector<int>& a, vector<int>& dp , int ind, int k)
{

dp[0]=0;
  for(int i=1;i<n;i++)
    {

int mm_steps=INT_MAX;
      for(int j=1;j<=k;j++)
        {
          if(i-j>=0)
            int jump=dp[i-j]+abs(a[i]-a[i-j]);
          mm_steps=min(jump, mm_steps);
        }
    
  dp[i]=mm_steps;
}

return dp[n-1];



}
