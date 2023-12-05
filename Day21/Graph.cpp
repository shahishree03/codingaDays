#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> shortdist(int n , int m , vector<vector<int>>& edges)
{
    vector<pair<int, int>> adj[n+1];
    for(auto it:edges)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n+1,1e9), parent(n+1);
    for(int i=1;i<=n;i++ ) parent[i]=i;
     dist[1]=0;
     pq.push({0,1});
      while(!pq.empty())
    {
        int dis = pq.top().first;
        int node=pq.top().second;

        pq.pop();
        for(auto it:adj[node])
        {
            int edgeWeight= it.second;
            int adjNode=it.first;

            if(dis+edgeWeight<dist[adjNode])
            {
                dist[adjNode]=dis+edgeWeight;
                pq.push({dist[adjNode], adjNode});
                parent[adjNode]=node;
            }

        }

    }
            if(dist[n]==1e9) return {-1};
            vector<int> path;
            int node=n;
            while (parent[node]!=node)
            {
                path.push_back(node);
                node=parent[node];
            }
            path.push_back(1);
            reverse(path.begin(), path.end());
            return path;
            
        }

    


vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V);
    for(int i=0;i<V;i++) dist[i]=1e9;

    dist[S]=0;
    pq.push({0,S});

    while(!pq.empty())
    {
        int dis = pq.top().first;
        int node=pq.top().second;

        pq.pop();

        for(auto it:adj[node])
        {
            int edgeWeight= it[1];
            int adjNode=it[0];

            if(dis+edgeWeight<dist[adjNode])
            {
                dist[adjNode]=dis+edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}
void dfs(int node, vector<int> adj[], int vis[], vector<int>& ls)
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
vector<int> dfsof(int V, vector<int> adj[])
{
    int visited[V]={0};
    visited[0]=1;
    int start=0;
    vector<int> ls;
    dfs(start, adj, visited, ls);
    return ls;
}
vector<int> bfs(int V, vector<int> adj[])
{
    int visites[V]={0};
    visites[0]=1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it : adj[node])
        {
            if(!visites[it])
            {
                visites[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
}
int main()
{

    //two way graph reprsesenation;

    /*int n, m;
    cin>>n>>m;
    int adj[n+1][m+1];
    for(int i=0;i<m;i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }

    //for undirected graph

    vector<int> adjo[n+1];
    for(int i=0;i<m;i++)
    {
        int u, v;
        cin>>u>>v;
        adjo[u].push_back(v);
        adjo[v].push_back(u);
    }*/

   // vector<vector<int>> adj[]=  {[1,2,2], [2,5,5], [2,3,4], [1,4,1],[4,3,3],[3,5,1]};
   /* vector<int> ans = dijkstra(1, adj, 2);
        for (int i = 0; i < 3; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;*/
 vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};
    vector<int> res = shortdist(5, 6, edges);
    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << "\n";
        
}