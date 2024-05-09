#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int> &happiness, int k) {
        long long res = 0;
        sort(happiness.begin(), happiness.end(), greater<>());
        for (int i = 0; i < k; i++) {
            int dt = happiness[i] - i;
            if (dt <= 0) break;
            res += dt;
        }
        return res;
    }
};