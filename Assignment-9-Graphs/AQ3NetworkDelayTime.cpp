#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<vector<pair<int,int>>> adj(N+1);

    for (auto &t : times) {
        int u = t[0], v = t[1], w = t[2];
        adj[u].push_back({v, w});
    }

    vector<int> dist(N+1, INT_MAX);
    dist[K] = 0;

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    pq.push({0, K});

    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();
        int d = top.first;
        int u = top.second;

        if (d > dist[u]) continue;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == INT_MAX) return -1;
        ans = max(ans, dist[i]);
    }
    return ans;
}

int main() {
    int N = 4, K = 2;
    vector<vector<int>> times = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };

    cout << networkDelayTime(times, N, K);
    return 0;
}
