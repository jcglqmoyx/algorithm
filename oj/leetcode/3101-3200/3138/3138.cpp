#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minAnagramLength(string s) {
        unordered_map<char, int> mp;
        for (char c: s) mp[c]++;
        int n = s.size();
        int g = -1;
        for (auto &[_, v]: mp) {
            if (g == -1) g = v;
            else g = gcd(g, v);
        }
        return n / g;
    }
};