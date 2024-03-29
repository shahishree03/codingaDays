class Sol
{
void solve(int i, vector<vector<int>> & a, int n , vector<string> &ans, string move, vector<vector<int>> &vis)
{
  if(i==n-1 &&j==n-1)
    ans.push_back(move);
  return;
//downward
  if(i+1<n && !vis[i+1][j] && a[i+1][j]==1)
  {
vis[i][j]=1;
    solve(i+1,j,a, n , move+'D', vis);
    vis[i][j]=0;

  }
//left
 if(j-1<n && !vis[i][j-1] && a[i][j-1]==1)
  {
vis[i][j]=1;
    solve(i,j-1, a, n , move+'L', vis);
    vis[i][j]=0;

  }

  //right
   if(j+1<n && !vis[i][j+1] && a[i][j+1]==1)
  {
vis[i][j]=1;
    solve(i+1,a, n , move+'R', vis);
    vis[i][j]=0;

  }
//upward
   if(i-1<n && !vis[i-1][j] && a[i-1][j]==1)
  {
vis[i][j]=1;
    solve(i+1,a, n , move+'U', vis);
    vis[i][j]=0;

  }


}
vector<vector<int>> func(vector<vector<int>>& arr, int N)
{
vector<string> ans;
  vector<vector<int>> vis(n, vector<int> (n,0));
  if(m[0][0] == 1) solve(0, 0, m , n, ans, "", vis);
  return ans;

}

};
