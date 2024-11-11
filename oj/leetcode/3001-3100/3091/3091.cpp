#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(int k) {
        int op1 = sqrt(k - 1);
        int op2 = (k - 1) / (op1 + 1);
        return op1 + op2;
    }
};