#include <iostream>
#include <vector>
#include <queue>
#include <climits>///
using namespace std;

void bfs(int n, vector<int> adj_list[], int start_node)
{
    queue<int> q;

    vector<int> visited(n, 0);
    vector<int> distance(n, INT_MAX);///

    visited[start_node] = 1;
    distance[start_node] = 0;///
    q.push(start_node);

    while(!q.empty())
    {
        int current_node = q.front();
        q.pop();

        for(int i = 0; i < adj_list[current_node].size(); i++)
        {
            int neighbor = adj_list[current_node][i];

            if(visited[neighbor] == 0)
            {
                visited[neighbor] = 1;

                distance[neighbor] = distance[current_node] + 1;///

                q.push(neighbor);
            }
        }
    }
    cout<<endl;

    for(int i = 0; i < n; i++)///
    {
        cout << "Distance of " << i << " = " << distance[i] << endl;
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

    bfs(n, adj_list, start_node);

    return 0;
}
