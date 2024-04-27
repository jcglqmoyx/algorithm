#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        auto n = ring.size(), m = key.size();
        bool st[n][m + 1];
        memset(st, 0, sizeof st);
        st[0][0] = true;
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        for (int step = 0;; step++) {
            queue<pair<int, int>> nxt;
            for (auto it = q.size(); it; it--) {
                int i = q.front().first, j = q.front().second;
                if (j == key.size()) return step;
                q.pop();
                if (ring[i] == key[j]) {
                    if (!st[i][j + 1]) {
                        nxt.emplace(i, j + 1);
                        st[i][j + 1] = true;
                    }
                } else {
                    for (int k: {(i - 1 + n) % n, (i + 1) % n}) {
                        if (!st[k][j]) {
                            nxt.emplace(k, j);
                            st[k][j] = true;
                        }
                    }
                }
            }
            q = std::move(nxt);
        }
    }
};