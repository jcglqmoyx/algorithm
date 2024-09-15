#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> map;
        map[0] = -1;
        int res = 0;
        unordered_map<char, int> p = {
                {'a', 0},
                {'e', 1},
                {'i', 2},
                {'o', 3},
                {'u', 4}
        };
        for (int mask = 0, i = 0; i < s.size(); i++) {
            if (p.count(s[i])) {
                mask ^= 1 << p[s[i]];
            }
            if (map.contains(mask)) {
                res = max(res, i - map[mask]);
            } else {
                map[mask] = i;
            }
        }
        return res;
    }
};