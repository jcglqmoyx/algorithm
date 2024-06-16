#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countCompleteDayPairs(vector<int> &hours) {
        long long res = 0;
        int cnt[24]{};
        for (int x: hours) {
            res += cnt[(24 - x % 24) % 24];
            cnt[x % 24]++;
        }
        return res;
    }
};