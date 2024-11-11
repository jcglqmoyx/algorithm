#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k) {
        struct Worker {
            int quality, wage;

            bool operator<(const Worker &worker) const {
                if (quality * worker.wage == worker.quality * wage) return wage < worker.wage;
                return quality * worker.wage > worker.quality * wage;
            }
        };
        auto n = quality.size();
        vector<Worker> v(n);
        for (int i = 0; i < n; i++) v[i] = {quality[i], wage[i]};
        sort(v.begin(), v.end());
        double res = 1e9;
        priority_queue<int> q;
        for (int sq = 0, i = 0; i < n; i++) {
            q.emplace(v[i].quality);
            sq += v[i].quality;
            if (i >= k - 1) {
                res = min(res, v[i].wage * 1.0 / v[i].quality * sq);
                sq -= q.top();
                q.pop();
            }
        }
        return res;
    }
};
