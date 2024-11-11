#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long totalCost(vector<int> &costs, int k, int candidates) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        auto n = costs.size();
        size_t l = 0, r = n - 1;
        for (; l < candidates; l++) {
            q.emplace(costs[l], l);
        }
        for (; r >= max(n - candidates, l); r--) {
            q.emplace(costs[r], r);
        }
        long long res = 0;
        while (k--) {
            auto t = q.top();
            q.pop();
            res += t.first;
            if (l <= r) {
                if (t.second < l) q.emplace(costs[l], l), l++;
                if (t.second > r) q.emplace(costs[r], r), r--;
            }
        }
        return res;
    }
};