#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxRemoval(vector<int> &nums, vector<vector<int>> &queries) {
        sort(queries.begin(), queries.end(), [&](auto &a, auto &b) {
            return a[0] < b[0];
        });
        int n = static_cast<int>(nums.size()), m = static_cast<int>(queries.size());
        int d[n + 2];
        memset(d, 0, sizeof d);
        priority_queue<int> q;
        for (int i = 1, j = 0; i <= n; i++) {
            d[i] += d[i - 1];
            while (j < m && queries[j][0] + 1 <= i) {
                q.emplace(queries[j][1] + 1);
                j++;
            }
            if (d[i] < nums[i - 1]) {
                while (d[i] < nums[i - 1]) {
                    if (q.empty()) {
                        return -1;
                    }
                    int t = q.top();
                    q.pop();
                    if (t >= i) {
                        d[i]++;
                        d[t + 1]--;
                    }
                }
            }
        }
        return static_cast<int> (q.size());
    }
};