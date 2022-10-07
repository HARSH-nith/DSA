#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfsTransversal)
{
    vis[node] = 1;
    storeDfsTransversal.push_back(node);
    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            dfs(it, vis, adj, storeDfsTransversal);
        }
    }
}

int main()
{
    int n, edges;
    cin >> n >> edges;
    vector<int> adj[n+1];
    for (int i = 0; i < edges; i++)
    { // creating adjency list for graph
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> vis(n + 1, 0); // initialise vis vector with initial value 0 each
    vector<int> storeDfsTransversal; // for storing dfs transverse 
    for (int i = 1; i <= n; i++)
        if (vis[i]==0)  dfs(i, vis, adj, storeDfsTransversal);
    cout << "DFS transverse as follow : ";
    for (auto node : storeDfsTransversal)
        cout << node << " ";
}
