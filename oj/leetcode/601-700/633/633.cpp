#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i = 0; i * i <= c - i * i; i++) {
            int b2 = c - i * i;
            int square = sqrt(b2);
            if (square * square == b2) {
                return true;
            }
        }
        return false;
    }
};