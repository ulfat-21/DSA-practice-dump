#include <iostream>
#include <vector>
using namespace std;

bool dfs(int current_node, int parent,
         vector<int> adj_list[], vector<int>& visited)
{
    visited[current_node] = 1;

    for(int i = 0; i < adj_list[current_node].size(); i++)
    {
        int neighbor = adj_list[current_node][i];

        if(visited[neighbor] == 0)
        {
            // NEW: current_node becomes neighbor-er parent
            if(dfs(neighbor, current_node, adj_list, visited))
            {
                return true;
            }
        }

        // NEW: visited, but amar parent na
        else if(neighbor != parent)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> adj_list[n];

    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    vector<int> visited(n, 0);

    bool cycle = false;

    // disconnected graph-o handle korbe
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            // NEW: starting node-er parent nai, tai -1
            if(dfs(i, -1, adj_list, visited))
            {
                cycle = true;
                break;
            }
        }
    }

    if(cycle)
        cout << "Cycle Found";
    else
        cout << "No Cycle";

    return 0;
}
