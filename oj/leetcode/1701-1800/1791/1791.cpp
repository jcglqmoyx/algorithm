#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>> &edges) {
        unordered_map<int, int> d;
        for (int i = 0; i <= 1; i++) {
            d[edges[i][0]]++;
            d[edges[i][1]]++;
        }
        for (int i = 0; i <= 1; i++) {
            for (int p: edges[i]) {
                if (d[p] == 2) {
                    return p;
                }
            }
        }
        return -1;
    }
};