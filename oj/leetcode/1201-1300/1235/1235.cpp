#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
        auto n = startTime.size();
        struct Job {
            int start_time, end_time, profit;
        };
        vector<Job> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(v.begin(), v.end(), [](const Job &a, const Job &b) {
            return a.end_time < b.end_time;
        });
        int res = 0;
        int f[n + 1];
        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; i++) {
            int l = 0, r = i - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (v[mid - 1].end_time <= v[i - 1].start_time) l = mid;
                else r = mid - 1;
            }
            f[i] = max(f[i - 1], f[l] + v[i - 1].profit);
        }
        return f[n];
    }
};