#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker) {
        auto n = difficulty.size();
        sort(worker.begin(), worker.end(), greater<>());
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            q.emplace(profit[i], difficulty[i]);
        }
        sort(worker.begin(), worker.end(), greater<>());
        int res = 0;
        for (int x: worker) {
            while (!q.empty() && q.top().second > x) q.pop();
            if (q.empty()) break;
            res += q.top().first;
        }
        return res;
    }
};