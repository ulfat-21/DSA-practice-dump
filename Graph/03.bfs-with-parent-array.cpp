///DISTANCE R PARENT ALADA JINISH JODI AKSHATHE USE KORA LAGE TAHOLE DIS ER CODER NICHE PAR ER CODE LIKHE DIBO SIMPLE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>///reverse use korar jonno
using namespace std;

void bfs(int n, vector<int> adj_list[], int start_node, int end_node)///
{
    queue<int> q;
    vector<int> visited(n, 0);
    vector<int> parent(n, -1);///
    visited[start_node] = 1;
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
                parent[neighbor] = current_node;///
                q.push(neighbor);
            }
        }
    }
    cout<<endl;
    ///PATH BUILDING
    int node = end_node;
    vector<int> path;

    while(node != -1)
    {
        path.push_back(node);
        node = parent[node];
    }

    reverse(path.begin(), path.end());

    cout << "Path: ";

    for(int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
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
    int start_node, end_node;///
    cin >> start_node >> end_node;
    bfs(n, adj_list, start_node, end_node);///
    return 0;
}
