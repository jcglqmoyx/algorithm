#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> mp;
        for (int i = 0; i + k - 1 < word.size(); i += k) {
            mp[word.substr(i, k)]++;
        }
        int n = (int) word.size(), res = n;
        for (auto &[_, v]: mp) {
            res = min(res, n / k - v);
        }
        return res;
    }
};