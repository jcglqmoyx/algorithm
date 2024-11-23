#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box) {
        int n = static_cast<int>(box.size()), m = static_cast<int>(box[0].size());
        vector<vector<char>> res(m, vector<char>(n, '.'));
        for (int i = n - 1; i >= 0; i--) {
            int p = m - 1;
            for (int j = m - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    p = j - 1;
                    res[j][n - i - 1] = '*';
                } else if (box[i][j] == '#') {
                    res[p][n - i - 1] = '#';
                    p--;
                } else {
                    res[j][n - i - 1] = '.';
                }
            }
        }
        return res;
    }
};