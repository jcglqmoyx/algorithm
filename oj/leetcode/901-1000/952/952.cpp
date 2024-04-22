#include <bits/stdc++.h>

using namespace std;

constexpr int N = 100010;

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
    int n;
    vector<int> p, sz;

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void connect(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (sz[px] > sz[py]) swap(px, py);
        sz[py] += sz[px];
        p[px] = py;
    }

public:
    int largestComponentSize(vector<int> &nums) {
        n = nums.size();
        p.resize(n);
        sz.resize(n);
        iota(p.begin(), p.end(), 0);
        fill(sz.begin(), sz.end(), 1);
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> mp(mx + 1, -1);
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }
        for (int i = 0; i < idx; i++) {
            int last = -1;
            for (int j = 1; pm[i] * j <= mx; j++) {
                if (mp[pm[i] * j] == -1) continue;
                int x = mp[pm[i] * j];
                if (last != -1) connect(last, x);
                last = x;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, sz[i]);
        }
        return res;
    }
};