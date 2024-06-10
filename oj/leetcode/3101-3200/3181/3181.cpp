#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxTotalReward(vector<int> &rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        rewardValues.erase(unique(rewardValues.begin(), rewardValues.end()), rewardValues.end());
        int m = rewardValues.back();
        unordered_set<int> s;
        for (int x: rewardValues) {
            if (x == m - 1 || s.contains(m - 1 - x)) return m * 2 - 1;
            s.emplace(x);
        }
        bitset<100000> f;
        f[0] = true;
        for (int x: rewardValues) {
            int shift = f.size() - x;
            f |= f << shift >> (shift - x);
        }
        for (int i = m * 2 - 1; i; i--) {
            if (f[i]) {
                return i;
            }
        }
        return -1;
    }
};