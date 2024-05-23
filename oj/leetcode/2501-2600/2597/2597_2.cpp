#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int beautifulSubsets(vector<int> &nums, int k) {
        unordered_map<int, map<int, int>> groups;
        for (int x: nums) {
            groups[x % k][x]++;
        }
        int f = 1;
        for (auto &[_, mp]: groups) {
            auto it = mp.begin();
            int a0 = 1, a1 = (1 << it->second) - 1;
            int pre = it->first;
            while (++it != mp.end()) {
                int b0 = a0 + a1, b1 = (a0 + (it->first - pre == k ? 0 : a1)) * ((1 << it->second) - 1);
                a0 = b0, a1 = b1;
                pre = it->first;
            }
            f *= (a0 + a1);
        }
        return f - 1;
    }
};