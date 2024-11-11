#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long distinctNames(vector<string> &ideas) {
        unordered_map<char, unordered_set<string>> m;
        for (auto &s: ideas) {
            m[s[0]].emplace(s.substr(1));
        }
        auto get = [&](auto &a, auto &b) {
            size_t res = 0;
            for (auto &s: a) {
                if (b.contains(s)) {
                    res++;
                }
            }
            return res;
        };
        long long res = 0;
        for (auto &[k1, v1]: m) {
            for (auto &[k2, v2]: m) {
                if (k1 == k2) continue;
                auto t = get(v1, v2);
                res += (v1.size() - t) * (v2.size() - t);
            }
        }
        return res;
    }
};