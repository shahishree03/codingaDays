class Sol{
public:
void dfs(int node, vector<int> adj[], vector<int> &ls)
{
vis[node]=1;
  ls.push_back(node);
  for(auto it:adj[node])
    {
if(!vis[it])
{
dfs(it, adj, vis, ls);
}
    }
}
vector<int> dfs(int n, vector<int> adj[])
{
int vis[n]={0};
int start=0;
vector<int> ls;
  dfs(start, adj, vis, ls);
  return ls

}

};
