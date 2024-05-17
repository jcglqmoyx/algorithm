#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        auto n = mat.size(), m = mat[0].size();
        vector<int> v = {0};
        for (int i = 0; i < n; i++) {
            vector<int> t;
            for (int x: v) {
                for (int y: mat[i]) {
                    t.emplace_back(x + y);
                }
            }
            sort(t.begin(), t.end());
            while (t.size() > k) t.pop_back();
            v = std::move(t);
        }
        return v.back();
    }
};