#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int> &changed) {
        auto n = changed.size();
        if (n & 1) return {};
        multiset<int> s(changed.begin(), changed.end());
        vector<int> res(n / 2);
        int i = 0;
        while (!s.empty()) {
            int x = *s.begin();
            s.erase(s.begin());
            auto it = s.find(x * 2);
            if (it == s.end()) return {};
            s.erase(it);
            res[i++] = x;
        }
        return res;
    }
};