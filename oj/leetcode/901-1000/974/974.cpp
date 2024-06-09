#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int> &nums, int k) {
        int res = 0;
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        for (int s = 0, i = 0; i < nums.size(); i++) {
            s = ((s + nums[i]) % k + k) % k;
            res += cnt[s];
            cnt[s]++;
        }
        return res;
    }
};