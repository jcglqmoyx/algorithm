#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img) {
        int n = static_cast<int>(img.size()), m = static_cast<int>(img[0].size());
        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cnt = 0, sum = 0;
                for (int a = max(0, i - 1); a <= min(n - 1, i + 1); a++) {
                    for (int b = max(0, j - 1); b <= min(m - 1, j + 1); b++) {
                        sum += img[a][b];
                        cnt++;
                    }
                }
                res[i][j] = sum / cnt;
            }
        }
        return res;
    }
};