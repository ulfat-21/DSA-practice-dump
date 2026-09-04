#include <iostream>
#include <vector>
using namespace std;

void dfs(int current_node, vector<int> adj_list[], vector<int>& visited)
{
    visited[current_node] = 1;

    cout << current_node << " ";

    for(int i = 0; i < adj_list[current_node].size(); i++)
    {
        int neighbor = adj_list[current_node][i];

        if(visited[neighbor] == 0)
        {
            dfs(neighbor, adj_list, visited);
        }
    }
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

    int start_node;
    cin >> start_node;

    cout << "DFS Sequence: ";
    dfs(start_node, adj_list, visited);


    return 0;
}
