#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<vector<int>> &queries, int k) {
        vector<int> res;
        res.reserve(queries.size());
        priority_queue<int> Q;
        for (auto &q: queries) {
            int d = abs(q[0]) + abs(q[1]);
            Q.emplace(d);
            if (Q.size() > k) {
                Q.pop();
            }
            if (Q.size() == k) {
                res.emplace_back(Q.top());
            } else {
                res.emplace_back(-1);
            }
        }
        return res;
    }
};