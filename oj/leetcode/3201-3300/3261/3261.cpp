#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>> &queries) {
        using ll = long long;
        auto n = s.size(), m = queries.size();
        int f[n + 1], cnt[2]{};
        ll sum[n + 1];
        sum[0] = 0;
        for (int l = 1, r = 1; r <= n; r++) {
            cnt[s[r - 1] & 1]++;
            while (cnt[0] > k && cnt[1] > k) {
                cnt[s[l - 1] & 1]--;
                l++;
            }
            f[r] = r - l + 1;
            sum[r] = sum[r - 1] + f[r];
        }

        vector<ll> res(m);
        for (int it = 0; it < m; it++) {
            int l = queries[it][0] + 1, r = queries[it][1] + 1;
            int lo = l - 1, hi = r;
            while (lo < hi) {
                int mid = (lo + hi + 1) >> 1;
                if (mid - f[mid] + 1 < l) lo = mid;
                else hi = mid - 1;
            }
            if (lo == l - 1) res[it] = sum[r] - sum[lo];
            else {
                ll len = lo - l + 1;
                res[it] = len * (len + 1) / 2;
                if (lo != r) {
                    res[it] += sum[r] - sum[lo];
                }
            }
        }
        return res;
    }
};