#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int> &nums, vector<int> &queries, int x) {
        vector<int> pos;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                pos.emplace_back(i);
            }
        }
        auto m = queries.size();
        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            res[i] = queries[i] > pos.size() ? -1 : pos[queries[i] - 1];
        }
        return res;
    }
};