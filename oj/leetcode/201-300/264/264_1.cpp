#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> s;
        s.emplace(1LL);
        while (--n) {
            auto x = *s.begin();
            s.erase(s.begin());
            s.emplace(x * 2);
            s.emplace(x * 3);
            s.emplace(x * 5);
        }
        return (int) *s.begin();
    }
};