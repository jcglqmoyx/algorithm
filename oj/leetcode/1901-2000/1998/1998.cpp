#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

bool st[N];
int pm[N >> 1], idx;
int pos[N];
int p[N];

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

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void connect(int x, int y) {
    int px = find(x), py = find(y);
    if (px != py) p[px] = py;
}

class Solution {
public:
    bool gcdSort(vector<int> &nums) {
        int mx = *max_element(nums.begin(), nums.end());
        memset(pos, -1, sizeof(int) * (mx + 1));
        auto n = nums.size();
        iota(p, p + n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (pos[nums[i]] != -1) {
                connect(pos[nums[i]], i);
            }
            pos[nums[i]] = i;
        }
        for (int i = 0; pm[i] <= mx; i++) {
            int last = -1;
            for (int x = pm[i]; x <= mx; x += pm[i]) {
                if (pos[x] != -1) {
                    if (last != -1) {
                        connect(pos[x], last);
                    }
                    last = pos[x];
                }
            }
        }
        vector<vector<pair<int, int>>> v(n);
        for (int i = 0; i < n; i++) {
            v[find(i)].emplace_back(nums[i], i);
        }
        for (auto &e: v) {
            auto m = e.size();
            vector<int> value(m), id(m);
            for (int i = 0; i < m; i++) {
                value[i] = {e[i].first};
                id[i] = {e[i].second};
            }
            sort(value.begin(), value.end());
            sort(id.begin(), id.end());
            for (int i = 0; i < m; i++) {
                nums[id[i]] = value[i];
            }
        }
        bool flag = true;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                flag = false;
                break;
            }
        }
        return flag;
    }
};