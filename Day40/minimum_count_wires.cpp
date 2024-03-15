#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void dfs(unordered_map<int, vector<int> >& adj, int node,
         vector<bool>& visited)
         {
             
             if(visited[node]) return;
             visited[node]=true;
             for(auto x:adj[node])
             {
                 if(visited[x]==false)
                 dfs(adj, x, visited);
             }
         }
int makeConnectionUtil(int n , vector<vector<int>>& conn , int m )
{
    unordered_map<int, vector<int>> adj;
    vector<bool> vis(n , false);
    int edges=0;
    for(int i=0;i<m;i++)
    {
        adj[conn[i][0]].push_back(conn[i][1]);
        adj[conn[i][0]].push_back(conn[i][1]);
        edges+=1;
    }
    
    int comp=0;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==false)
        {
            comp+=1;
            dfs(adj,i, vis);
        }
    }
    if(edges<n-1) return -1;
    int red =edges-((n-1)-(comp-1));
    
    if(red>=(comp-1))
    return comp-1;
    
    return -1;
}
void makeConnection(int n, vector<vector<int>>& conn, int m)
{
    int minOps =makeConnectionUtil(n , conn, m);
    cout<<minOps;
}

int main()
{
 int n=4;
 vector<vector<int>> conn= {{0, 1}, {0,2}, {1,2}};
 makeConnection(4, conn, 3);
}
