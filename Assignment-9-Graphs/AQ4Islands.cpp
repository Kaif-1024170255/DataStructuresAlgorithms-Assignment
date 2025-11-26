#include <bits/stdc++.h>
using namespace std;

// DFS
void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
    int m = grid.size(), n = grid[0].size();
    vis[x][y] = true;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
            !vis[nx][ny] && grid[nx][ny] == 1) {
            dfs(nx, ny, grid, vis);
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    vector<vector<bool>> vis(m, vector<bool>(n, false));
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && !vis[i][j]) {
                count++;
                dfs(i, j, grid, vis);
            }
        }
    }

    cout << count;
    return 0;
}
