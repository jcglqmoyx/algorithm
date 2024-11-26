#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<int> order;
        int d[numCourses];
        memset(d, 0, sizeof d);
        int m = static_cast<int>(prerequisites.size()) + 1;
        int h[numCourses], e[m], ne[m], idx = 0;
        memset(h, -1, sizeof h);
        for (auto &p: prerequisites) {
            e[idx] = p[0], ne[idx] = h[p[1]], h[p[1]] = idx++;
            d[p[0]]++;
        }
        int q[numCourses];
        int hh = 0, tt = -1;
        for (int i = 0; i < numCourses; i++) {
            if (!d[i]) {
                order.emplace_back(i);
                q[++tt] = i;
            }
        }
        while (hh <= tt) {
            int t = q[hh++];
            for (int i = h[t]; ~i; i = ne[i]) {
                if (--d[e[i]] == 0) {
                    q[++tt] = e[i];
                    order.emplace_back(e[i]);
                }
            }
        }
        if (order.size() != numCourses) {
            order.clear();
        }
        return order;
    }
};