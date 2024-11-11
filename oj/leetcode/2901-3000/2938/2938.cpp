#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        long long sum = 0, cnt0 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') cnt0++, sum += i;
        }
        return sum - cnt0 * (cnt0 - 1) / 2;
    }
};