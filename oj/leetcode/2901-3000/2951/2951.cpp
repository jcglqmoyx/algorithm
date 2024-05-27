#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findPeaks(vector<int> &mountain) {
        vector<int> res;
        for (int i = 1; i + 1 < mountain.size(); i++) {
            if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1]) {
                res.emplace_back(i);
                i++;
            }
        }
        return res;
    }
};