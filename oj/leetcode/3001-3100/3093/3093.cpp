#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> stringIndices(vector<string> &wordsContainer, vector<string> &wordsQuery) {
        int n = static_cast<int>(wordsQuery.size());
        int tot = 1;
        int shortest = 1e8, shortest_idx = -1;
        for (int i = 0; i < wordsContainer.size(); i++) {
            int len = static_cast<int>(wordsContainer[i].size());
            tot += len;
            if (len < shortest) {
                shortest = len;
                shortest_idx = i;
            }
        }
        int tr[tot][26], min_length[tot], index[tot], idx = 0;
        memset(tr, 0, sizeof tr);
        memset(min_length, 0x3f, sizeof min_length);
        index[0] = shortest_idx;
        auto insert = [&](int u) {
            int m = static_cast<int>(wordsContainer[u].size());
            int p = 0;
            for (int i = m - 1; i >= 0; i--) {
                int c = wordsContainer[u][i] - 'a';
                if (!tr[p][c]) tr[p][c] = ++idx;
                p = tr[p][c];
                if (min_length[p] > m) {
                    min_length[p] = m;
                    index[p] = u;
                }
            }
        };
        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(i);
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            auto &s = wordsQuery[i];
            int m = static_cast<int>(s.size());
            int p = 0;
            for (int j = m - 1; j >= 0; j--) {
                int u = s[j] - 'a';
                if (tr[p][u]) {
                    p = tr[p][u];
                } else {
                    break;
                }
            }
            res[i] = index[p];
        }
        return res;
    }
};