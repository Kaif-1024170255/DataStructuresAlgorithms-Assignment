#include <iostream>
using namespace std;

struct Edge { int u, v, w; };

void addEdge(vector<vector<pair<int,int>>>& adj, int u, int v, int w, bool undirected = true) {
    adj[u].push_back({v, w});
    if (undirected) adj[v].push_back({u, w});
}

// BFS
void BFS(const vector<vector<pair<int,int>>>& adj, int start) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    cout << "BFS: ";
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (size_t i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << "\n";
}

// DFS
void DFSUtil(int u, const vector<vector<pair<int,int>>>& adj, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";
    for (size_t i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].first;
        if (!visited[v]) DFSUtil(v, adj, visited);
    }
}

void DFS(const vector<vector<pair<int,int>>>& adj, int start) {
    vector<bool> visited(adj.size(), false);
    cout << "DFS: ";
    DFSUtil(start, adj, visited);
    cout << "\n";
}

// DSU
struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n,0) { for (int i = 0; i < n; i++) parent[i] = i; }
    int find(int x) { return (parent[x] == x) ? x : parent[x] = find(parent[x]); }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a != b) {
            if (rank[a] < rank[b]) swap(a,b);
            parent[b] = a;
            if (rank[a] == rank[b]) rank[a]++;
        }
    }
};

// Kruskal
void Kruskal(const vector<vector<pair<int,int>>>& adj) {
    vector<Edge> edges;
    int n = adj.size();

    for (int u = 0; u < n; u++) {
        for (size_t i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if (u < v) edges.push_back({u, v, w});
        }
    }

    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b){ return a.w < b.w; });

    DSU dsu(n);
    cout << "Kruskal MST:\n";
    for (size_t i = 0; i < edges.size(); i++) {
        Edge e = edges[i];
        if (dsu.find(e.u) != dsu.find(e.v)) {
            cout << e.u << " -- " << e.v << " (w=" << e.w << ")\n";
            dsu.unite(e.u, e.v);
        }
    }
}

// Prim
void Prim(const vector<vector<pair<int,int>>>& adj, int start) {
    int n = adj.size();
    vector<bool> inMST(n, false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});

    cout << "Prim MST:\n";
    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();
        int w = top.first, u = top.second;
        if (inMST[u]) continue;

        inMST[u] = true;
        if (w != 0) cout << "Node " << u << " cost=" << w << "\n";

        for (size_t i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int wt = adj[u][i].second;
            if (!inMST[v]) pq.push({wt, v});
        }
    }
}

// Dijkstra
void Dijkstra(const vector<vector<pair<int,int>>>& adj, int start) {
    int n = adj.size();
    vector<int> dist(n, INT_MAX);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();
        int d = top.first, u = top.second;
        if (d > dist[u]) continue;

        for (size_t i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Dijkstra Distances:\n";
    for (int i = 0; i < n; i++)
        cout << i << ": " << dist[i] << "\n";
}

int main() {
    int n = 6;
    vector<vector<pair<int,int>>> adj(n);

    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 2, 1);
    addEdge(adj, 1, 3, 2);
    addEdge(adj, 2, 3, 5);
    addEdge(adj, 1, 4, 3);
    addEdge(adj, 3, 5, 8);

    BFS(adj, 0);
    DFS(adj, 0);
    Kruskal(adj);
    Prim(adj, 0);
    Dijkstra(adj, 0);

    return 0;
}
