#include <iostream>
#include <vector>
using namespace std;

int row, col;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dfs(int current_row, int current_col,
         vector<vector<char>>& grid,
         vector<vector<int>>& visited)
{
    visited[current_row][current_col] = 1;

    cout << "(" << current_row << "," << current_col << ") ";

    for(int i = 0; i < 4; i++)
    {
        int new_row = current_row + dr[i];
        int new_col = current_col + dc[i];

        if(new_row >= 0 && new_row < row &&
           new_col >= 0 && new_col < col &&
           visited[new_row][new_col] == 0 &&
           grid[new_row][new_col] == '.')
        {
            dfs(new_row, new_col, grid, visited);
        }
    }
}

int main()
{
    cin >> row >> col;

    vector<vector<char>> grid(row, vector<char>(col));

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> visited(row, vector<int>(col, 0));

    int start_row, start_col;
    cin >> start_row >> start_col;

    cout << "DFS Sequence: ";
    dfs(start_row, start_col, grid, visited);

    return 0;
}
