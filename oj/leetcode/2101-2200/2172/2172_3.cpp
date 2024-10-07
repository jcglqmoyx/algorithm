#include <bits/stdc++.h>

using namespace std;

const int N = 33, INF = 1e9;

template<typename T>
struct ZKW_SPFA {
    struct Edge {
        int v, nex;
        T w, c;

        Edge(const int &_v, const int &_nex, const T &_w, const T &_c) : v(_v), nex(_nex), w(_w), c(_c) {}
    };

    vector<Edge> e;
    int n, s, t;
    int fir[N], vis[N];
    T maxflow, mincost;
    T dis[N];

    ZKW_SPFA() { e.reserve(N << 4); }

    void init(const int &_n) {
        n = _n;
        maxflow = mincost = 0;
        e.clear();
        memset(fir, -1, sizeof(int) * (n + 3));
    }

    void add_edge(const int &u, const int &v, const T &w = 1, const T &c = 0) {
        e.emplace_back(v, fir[u], w, c);
        fir[u] = e.size() - 1;
        e.emplace_back(u, fir[v], 0, -c);
        fir[v] = e.size() - 1;
    }

    pair<T, T> work(const int &_s, const int &_t) {
        s = _s;
        t = _t;
        while (spfa()) {
            vis[t] = 1;
            while (vis[t]) {
                memset(vis, 0, sizeof(int) * (n + 3));
                maxflow += dfs(s, INF);
            }
        }
        return {maxflow, mincost};
    }

private:
    bool spfa() {
        memset(dis, 0x3f, sizeof(T) * (n + 3));
        memset(vis, 0, sizeof(int) * (n + 3));
        deque<int> q;
        q.push_back(t);
        dis[t] = 0;
        vis[t] = 1;
        while (q.size()) {
            int u = q.front();
            q.pop_front();
            for (int i = fir[u], v; ~i; i = e[i].nex) {
                v = e[i].v;
                if (!e[i ^ 1].w || dis[v] <= dis[u] + e[i ^ 1].c) continue;
                dis[v] = dis[u] + e[i ^ 1].c;
                if (vis[v]) continue;
                vis[v] = 1;
                if (q.size() && dis[v] < dis[q.front()]) q.push_front(v);
                else q.push_back(v);
            }
            vis[u] = 0;
        }
        return dis[s] < INF;
    }

    T dfs(const int &u, const T &flow) {
        vis[u] = 1;
        if (u == t || flow <= 0) return flow;
        T res, used = 0;
        for (int i = fir[u], v; ~i; i = e[i].nex) {
            v = e[i].v;
            if (vis[v] || !e[i].w || dis[u] != dis[v] + e[i].c) continue;
            res = dfs(v, min(e[i].w, flow - used));
            if (!res) continue;
            mincost += res * e[i].c;
            e[i].w -= res;
            e[i ^ 1].w += res;
            used += res;
            if (used == flow) break;
        }
        return used;
    }
};

class Solution {
public:
    int maximumANDSum(vector<int> &nums, int numSlots) {
        int n = nums.size();
        ZKW_SPFA<int> flow;
        int S = n + numSlots + 1, T = n + numSlots + 2;
        flow.init(n + numSlots + 2);
        for (int i = 0; i < n; ++i) {
            flow.add_edge(S, i + 1, 1, 0);
            for (int j = 1; j <= numSlots; ++j) {
                flow.add_edge(i + 1, n + j, 1, -(nums[i] & j));
            }
        }
        for (int i = 1; i <= numSlots; ++i) flow.add_edge(n + i, T, 2, 0);
        return -flow.work(S, T).second;
    }
};