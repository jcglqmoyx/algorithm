#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
        auto n = arr.size(), m = queries.size();
        int s[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] ^ arr[i - 1];
        }
        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            res[i] = s[queries[i][1] + 1] ^ s[queries[i][0]];
        }
        return res;
    }
};