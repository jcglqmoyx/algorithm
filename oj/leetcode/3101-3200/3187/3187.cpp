#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int tr[N];

bool check(vector<int> &nums, int x) {
    bool res = x && x + 1 < nums.size() && nums[x] > nums[x - 1] && nums[x] > nums[x + 1];
    return res;
}

void update(int x, int v) {
    if (x == 0) return;
    while (x <= n) {
        tr[x] += v;
        x += x & -x;
    }
}

int query(int x) {
    int res = 0;
    while (x) {
        res += tr[x];
        x -= x & -x;
    }
    return res;
}

void modify(vector<int> &nums, int p, int idx, int v) {
    int old_value = check(nums, p);
    nums[idx] = v;
    int new_value = check(nums, p);
    update(p, new_value - old_value);
}

class Solution {
public:
    vector<int> countOfPeaks(vector<int> &nums, vector<vector<int>> &queries) {
        n = nums.size();
        memset(tr, 0, sizeof(int) * (n + 5));
        nums.insert(nums.begin(), 1e9);
        nums.push_back(1e9);
        for (int i = 1; i <= n; i++) {
            update(i, check(nums, i));
        }
        vector<int> res;
        for (auto &q: queries) {
            q[1]++;
            if (q[0] == 1) {
                q[2]++;
                res.emplace_back(max(0, query(q[2] - 1) - query(q[1])));
            } else {
                int o = nums[q[1]];
                modify(nums, q[1] - 1, q[1], q[2]);
                nums[q[1]] = o;

                modify(nums, q[1] + 1, q[1], q[2]);
                nums[q[1]] = o;

                modify(nums, q[1], q[1], q[2]);
            }
        }
        return res;
    }
};