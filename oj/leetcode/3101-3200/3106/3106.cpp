#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getSmallestString(string s, int k) {
        for (int i = 0; i < s.size() && k; i++) {
            int dt = min(s[i] - 'a', 'z' - s[i] + 1);
            if (dt > k) {
                s[i] -= k;
                break;
            }
            s[i] = 'a';
            k -= dt;
        }
        return s;
    }
};