#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char kthCharacter(long long k, vector<int> &operations) {
        int change = 0;
        auto get = [&](auto &&get) -> char {
            if (k == 1) return change % 26 + 'a';
            long long t = 1;
            int op = 0;
            while ((t << 1) < k) {
                t <<= 1;
                op++;
            }
            change += operations[op];
            k -= t;
            return get(get);
        };
        return get(get);
    }
};