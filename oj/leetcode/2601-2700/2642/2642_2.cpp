#include <bits/stdc++.h>

using namespace std;

static constexpr int N = 105, M = N * N;

int h[N], w[M], e[M], ne[M], idx;

void add(const int a, const int b, const int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

class Graph {
    int n;

public:
    Graph(const int n, const vector<vector<int>>&edges) {
        idx = 0;
        this->n = n;
        memset(h, -1, sizeof(int) * n);
        for (auto&e: edges) {
            add(e[0], e[1], e[2]);
        }
    }

    static void addEdge(const vector<int>&edge) {
        add(edge[0], edge[1], edge[2]);
    }

    int shortestPath(int node1, const int node2) const {
        int dist[n];
        bool st[n];
        memset(dist, 0x3f, sizeof dist);
        memset(st, false, sizeof st);
        dist[node1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.emplace(0, node1);
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            if (st[t.second]) continue;
            st[t.second] = true;
            for (int i = h[t.second]; ~i; i = ne[i]) {
                int j = e[i];
                if (dist[j] > t.first + w[i]) {
                    dist[j] = t.first + w[i];
                    q.emplace(dist[j], j);
                }
            }
        }
        return dist[node2] == 0x3f3f3f3f ? -1 : dist[node2];
    }
};
