#include <bits/stdc++.h>

using namespace std;

const int N = 100010, M = N << 1;

int h[N], e[M], ne[M], idx;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations) {
        memset(h, -1, sizeof(int) * n), idx = 0;
        for (auto &e: invocations) {
            add(e[0], e[1]);
        }
        bool suspicious[n];
        memset(suspicious, false, sizeof suspicious);
        queue<int> q;
        q.emplace(k);
        suspicious[k] = true;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            for (int i = h[t]; ~i; i = ne[i]) {
                if (suspicious[e[i]]) continue;
                q.emplace(e[i]);
                suspicious[e[i]] = true;
            }
        }
        for (auto &e: invocations) {
            if (suspicious[e[1]] && !suspicious[e[0]]) {
                vector<int> res(n);
                iota(res.begin(), res.end(), 0);
                return res;
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) res.emplace_back(i);
        }
        return res;
    }
};