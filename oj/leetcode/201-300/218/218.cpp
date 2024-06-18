#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        auto n = buildings.size();
        vector<pair<int, int>> v;
        v.reserve(n * 2);
        for (auto &b: buildings) {
            v.emplace_back(b[0], -b[2]);
            v.emplace_back(b[1], b[2]);
        }
        sort(v.begin(), v.end());
        multiset<int> heights;
        heights.emplace(0);
        vector<vector<int>> res;
        for (auto &p: v) {
            int x = p.first, h = abs(p.second);
            if (p.second < 0) {
                if (h > *heights.rbegin()) {
                    res.push_back({x, h});
                }
                heights.emplace(h);
            } else {
                heights.erase(heights.find(h));
                if (h > *heights.rbegin()) {
                    res.push_back({x, *heights.rbegin()});
                }
            }
        }
        return res;
    }
};