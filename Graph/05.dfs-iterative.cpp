#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int n, vector<int> adj_list[], int start_node)
{
    stack<int> s;
    vector<int> visited(n, 0);

    visited[start_node] = 1;
    s.push(start_node);

    cout << "DFS Sequence: ";

    while(!s.empty())
    {
        int current_node = s.top();
        s.pop();

        cout << current_node << " ";

        for(int i = 0; i < adj_list[current_node].size(); i++)
        {
            int neighbor = adj_list[current_node][i];

            if(visited[neighbor] == 0)
            {
                visited[neighbor] = 1;
                s.push(neighbor);
            }
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

    int start_node;
    cin >> start_node;

    dfs(n, adj_list, start_node);

    return 0;
}
