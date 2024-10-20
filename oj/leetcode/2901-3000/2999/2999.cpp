#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        using LL = long long;
        LL pow[16];
        pow[0] = 1;
        for (int i = 1; i < 16; i++) pow[i] = pow[i - 1] * (limit + 1);
        auto fn = [&](LL num) -> LL {
            vector<int> v;
            LL x = num;
            while (x) {
                v.emplace_back(x % 10);
                x /= 10;
            }
            int n = static_cast<int>(v.size());
            if (n < s.size()) return 0LL;
            else if (n == s.size()) return to_string(num) >= s;

            LL res = pow[n - 1 - s.size()];

            for (int i = n - 1; i >= s.size(); i--) {
                LL t = (min(v[i] - 1, limit)) + 1;
                if (i == n - 1) t--;
                t *= pow[i - s.size()];
                res += t;
                if (v[i] > limit) break;
                if (i == s.size()) {
                    res += to_string(num).substr(n - s.size()) >= s;
                }
            }
            return res;
        };
        return fn(finish) - fn(start - 1);
    }
};