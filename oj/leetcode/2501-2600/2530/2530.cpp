#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxKelements(vector<int> &nums, int k) {
        long long res = 0;
        priority_queue<int> q(nums.begin(), nums.end());
        while (k--) {
            int x = q.top();
            if (x == 1) break;
            q.pop();
            res += x;
            q.emplace((x + 2) / 3);
        }
        return res + k + 1;
    }
};