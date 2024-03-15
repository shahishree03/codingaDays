class Sol{
public:
vector<int> bfsofGraph(int n, vector<int> adj[])
{
int vis[n]={0};
  vis[0]=1;
  queue<int> q;
  vector<int> bfs;
  q.push(0);
  while(!q.empty())
    {
  int node=q.front();
      q.pop();
      bfs.push(node);
      for(auto it:adj[node])
        {
          if(!vis[it])
          {
         vis[it]=1;
            q.push(it);
          }
        }
    }
  return bfs;
}
};
