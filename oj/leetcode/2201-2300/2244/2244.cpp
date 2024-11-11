#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumRounds(vector<int> &tasks) {
        unordered_map<int, int> cnt;
        for (auto t: tasks) cnt[t]++;
        int res = 0;
        for (auto &[_, v]: cnt) {
            if (v < 2) return -1;
            res += (v + 2) / 3;
        }
        return res;
    }
};