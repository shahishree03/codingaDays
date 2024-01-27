int a(vector<int>& ar, int dp, int i)
{
  if(i==0) return 0;
  if(dp[i]!=-1) return dp[i];
int left = a(ar, dp, n-1)+abs(a[i]-a[i-1]);
  if(n>1)
    int right=INT_MAX;
  right =a(ar, dp, n-2)+abs(a[i]-a[i-2]);
  return dp[i] =min(left, right);
}

void tab(int n , vector<int>& ar)
{
vector<int> dp(n,0);
  dp[0]=0;
  for(int i=1;i<n;i++)
    {
   int fs =dp[i-1]+abs(a[i]-a[i-1]);
      int ss= INT_MAX;
      if(i>1) ss= dp[i-2]+abs(a[i]-a[i-2]);
      dp[i]=min(fs,ss);
      return dp[n-1];
    }
}


