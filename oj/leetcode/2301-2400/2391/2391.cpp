#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel) {
        int n = garbage.size();
        unordered_map<char, int> mp;
        int res = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (char c: garbage[i]) {
                if (!mp.contains(c)) {
                    mp[c] = i;
                }
            }
            res += garbage[i].size();
        }
        for (int d = 0, i = 1; i < n; i++) {
            d += travel[i - 1];
            for (auto &[_, v]: mp) {
                if (v == i) {
                    res += d;
                }
            }
        }
        return res;
    }
};