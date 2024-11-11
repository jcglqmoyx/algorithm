#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> get(vector<int> &code, int k) {
        auto n = code.size();
        vector<int> res(n);
        for (int s = 0, i = 0; i < n + k; i++) {
            s += code[i % n];
            if (i >= k) {
                s -= code[(i - k + n) % n];
                res[i - k] = s;
            }
        }
        return res;
    }

public:
    vector<int> decrypt(vector<int> &code, int k) {
        if (k >= 0) {
            return get(code, k);
        } else {
            reverse(code.begin(), code.end());
            auto t = get(code, -k);
            reverse(t.begin(), t.end());
            return t;
        }
    }
};