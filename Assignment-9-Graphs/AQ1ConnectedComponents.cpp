#include <bits/stdc++.h>
using namespace std;

void DFS(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            DFS(v, adj, visited);
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);
    vector<bool> visited(V, false);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int components = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            components++;
            DFS(i, adj, visited);
        }
    }

    cout << components;
    return 0;
}
