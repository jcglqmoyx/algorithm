#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int edgeScore(vector<int> &edges) {
        auto n = edges.size();
        long long score[n];
        memset(score, 0, sizeof score);
        for (int i = 0; i < n; i++) {
            score[edges[i]] += i;
        }
        long long mx = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (score[i] > mx) {
                mx = score[i];
                res = i;
            }
        }
        return res;
    }
};