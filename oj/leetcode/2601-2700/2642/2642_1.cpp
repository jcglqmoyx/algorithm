#include <bits/stdc++.h>

using namespace std;

class Graph {
    int n;
    vector<vector<int>> dist;

public:
    Graph(int n, vector<vector<int>>&edges) {
        this->n = n;
        dist.resize(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        for (auto&e: edges) {
            dist[e[0]][e[1]] = e[2];
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    void addEdge(vector<int> edge) {
        int x = edge[0], y = edge[1], w = edge[2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][x] + dist[y][j] + w);
            }
        }
    }

    int shortestPath(int node1, int node2) {
        return dist[node1][node2] == 1e9 ? -1 : dist[node1][node2];
    }
};
