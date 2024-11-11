#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int duplicateNumbersXOR(vector<int> &nums) {
        long long vis = 0;
        int res = 0;
        for (int x: nums) {
            if (vis >> x & 1) res ^= x;
            vis |= 1LL << x;
        }
        return res;
    }
};