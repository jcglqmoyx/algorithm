#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>> &paths) {
        unordered_set < string > s;
        for (auto &p: paths) {
            s.emplace(p[0]);
        }
        for (auto &p: paths) {
            if (!s.contains(p[1])) {
                return p[1];
            }
        }
        return "";
    }
};