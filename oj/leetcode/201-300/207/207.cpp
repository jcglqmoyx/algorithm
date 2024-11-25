#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        int d[numCourses];
        memset(d, 0, sizeof d);
        int m = static_cast<int> (prerequisites.size()) + 1;
        int h[numCourses], e[m], ne[m], idx = 0;
        memset(h, -1, sizeof h);
        for (auto &p: prerequisites) {
            d[p[0]]++;
            e[idx] = p[0], ne[idx] = h[p[1]], h[p[1]] = idx++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (!d[i]) {
                q.emplace(i);
            }
        }
        int cnt = 0;
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            cnt++;
            for (int i = h[t]; ~i; i = ne[i]) {
                int j = e[i];
                if (!--d[j]) {
                    q.emplace(j);
                }
            }
        }
        return cnt == numCourses;
    }
};