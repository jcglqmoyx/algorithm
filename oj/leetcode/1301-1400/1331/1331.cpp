#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int> &arr) {
        set<int> s;
        for (int x: arr) s.emplace(x);
        unordered_map<int, int> rank;
        int idx = 1;
        for (int x: s) rank[x] = idx++;
        vector<int> res(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            res[i] = rank[arr[i]];
        }
        return res;
    }
};