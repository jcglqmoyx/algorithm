#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isBalanced(string num) {
        int o = 0, e = 0;
        for (int i = 0; i < num.size(); i++) {
            if (i & 1) o += num[i] - '0';
            else e += num[i] - '0';
        }
        return o == e;
    }
};