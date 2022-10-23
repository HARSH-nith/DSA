// Number of Provinces-  A province is a group of directly or indirectly connected cities and no other cities outside of the group.

#include <iostream>
#include <vector>

using namespace std;

int numProvinces(vector<vector<int>> adj, int V);
void dfs(vector<vector<int>> adj, int i, vector<int> &vis, int V);

int main()
{
  vector<vector<int>> adj{{1, 0, 1},
                          {0, 1, 0},
                          {1, 0, 1}};
  cout << "Number of Provinces are: " << numProvinces(adj, 2) << endl;
}

int numProvinces(vector<vector<int>> adj, int V)
{
  int count = 0;         // initialising count
  vector<int> vis(V, 0); // initialising visited array as all not visited

  for (int i = 0; i < V; i++) // iterating through the provinces
  {
    if (vis[i] == 0) // if the province is not visited
    {
      dfs(adj, i, vis, V); // call the funct
      count++;             // count incremented when all its neigh are visted
    }
  }
  return count;
}

void dfs(vector<vector<int>> adj, int i, vector<int> &vis, int V)
{
  vis[i] = 1; // marking the province visited

  for (int j = 0; j < V; j++) // iterating
  {
    if (adj[i][j] == 1 && vis[j] == 0) // if the neigh is present and not visited
    {
      dfs(adj, j, vis, V); // call
    }
  }
}

/*
approach
- we got a 2D array so we start from the top left and call dfs from there
- we keep in a visited array so that we don't visit a province more than once
- we change the visited flag of the top left node from 0 to 1
- then we visit the neighbouring province if it's not already visited
- this function call will end when all the provinces connected to top left node are visited and count becomes 1
- now same will be done for rest of the provinces, starting from the one that's is not visited
-
*/