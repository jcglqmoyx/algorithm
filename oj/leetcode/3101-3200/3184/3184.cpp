#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countCompleteDayPairs(vector<int> &hours) {
        int mp[24]{}, res = 0;
        for (int x: hours) {
            res += mp[(24 - x % 24) % 24];
            mp[x % 24]++;
        }
        return res;
    }
};