class Sol{
private:

void bfs(int row, int col, vector<vectot<int>>& vis, vector<vector<int>> grid)
{
vis[row][col]=1;
  queue<pair<int, int>> q;
  q.push({row, col});
  while(!q.empty())
    {
int r= q.front.first();
      int c=q.front.second();
      q.pop();
      for(int i=-1;i<=1;i++)
        {
          for(int j=-1;j<=1;j++)
            int nr=r+i;
          int nc=c+j;
            {
if(nc>=0 && nc<m && nr>=0 && nr<n&& grid[nr][nc] =='1' && !vis[nr][nc])
{
vis[nr][nc]=1;
  q.push({nr, nc});
}

            }
        }

    }
}
public:
int num_of_Islands(vector<vector<int>>& grids)
{
 int n =grid.size();
  int m =grid[0].size();
  vector<vector<int>> vis(n, vector<int>(m,0));
  for(int row =0;row<n;row++)
    {
for(int col=0;col<m;col++)
  {
if(!vis[row][col])
{
cnt++;
  bfs(row, col, vis, grid);
}
  }

  }
  
}
};
