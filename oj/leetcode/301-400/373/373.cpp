#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        struct T {
            int i, j;
            int x, y;

            bool operator<(const T &t) const {
                return x + y > t.x + t.y;
            }
        };
        auto n = nums1.size(), m = nums2.size();
        priority_queue<T> q;
        for (int i = 0; i < n; i++) {
            q.emplace(i, 0, nums1[i], nums2[0]);
        }
        vector<vector<int>> res;
        res.reserve(k);
        while (k--) {
            auto t = q.top();
            q.pop();
            res.push_back({t.x, t.y});
            if (t.j < m - 1) q.emplace(t.i, t.j + 1, nums1[t.i], nums2[t.j + 1]);
        }
        return res;
    }
};