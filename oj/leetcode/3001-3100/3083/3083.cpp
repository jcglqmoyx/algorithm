#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool isSubstringPresent(string s) {
        unordered_set<string> set;
        for (int i = 0; i + 1 < s.size(); i++) {
            set.insert(s.substr(i, 2));
        }
        ranges::reverse(s.begin(), s.end());
        for (int i = 0; i + 1 < s.size(); i++) {
            if (set.contains(s.substr(i, 2))) {
                return true;
            }
        }
        return false;
    }
};
