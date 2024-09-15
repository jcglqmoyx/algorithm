#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxPathLength(vector<vector<int>> &coordinates, int k) {
        int kx = coordinates[k][0], ky = coordinates[k][1];
        sort(coordinates.begin(), coordinates.end(), [](auto &a, auto &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<int> v;
        for (auto &c: coordinates) {
            if (c[0] < kx && c[1] < ky || c[0] > kx && c[1] > ky) {
                auto it = lower_bound(v.begin(), v.end(), c[1]);
                if (it == v.end()) v.emplace_back(c[1]);
                else *it = c[1];
            }
        }
        return v.size() + 1;
    }
};