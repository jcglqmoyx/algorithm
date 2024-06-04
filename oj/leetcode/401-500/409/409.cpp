#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int, int> mp;
        for (char c: s) mp[c]++;
        int res = 0;
        int odd = 0;
        for (auto &[_, cnt]: mp) {
            if (cnt & 1) {
                if (!odd) {
                    res += cnt;
                    odd = 1;
                } else {
                    res += cnt - 1;
                }
            } else {
                res += cnt;
            }
        }
        return res;
    }
};