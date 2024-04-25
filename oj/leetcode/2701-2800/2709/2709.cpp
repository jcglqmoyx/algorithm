#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

bool st[N];
int pm[N >> 1], idx;

int init = []() {
    for (int i = 2; i < N; i++) {
        if (!st[i]) pm[idx++] = i;
        for (int j = 0; pm[j] * i < N; j++) {
            st[pm[j] * i] = true;
            if (i % pm[j] == 0) break;
        }
    }
    return 0;
}();

class Solution {
    vector<int> p;

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void connect(int x, int y) {
        p[find(x)] = find(y);
    }

public:
    bool canTraverseAllPairs(vector<int> &nums) {
        auto n = nums.size();
        if (n == 1) return true;
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        int mx = *max_element(nums.begin(), nums.end());
        vector<vector<int>> mp(mx + 1);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) return false;
            mp[nums[i]].emplace_back(i);
        }
        for (int i = 0; pm[i] <= mx; i++) {
            for (int last = -1, x = pm[i]; x <= mx; x += pm[i]) {
                for (auto &id: mp[x]) {
                    if (last != -1) connect(last, id);
                    last = id;
                }
            }
        }
        int p0 = find(0);
        for (int i = 1; i < n; i++) {
            if (find(i) != p0) return false;
        }
        return true;
    }
};