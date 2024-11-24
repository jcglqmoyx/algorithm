#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canAliceWin(int n) {
        return (int) (21 - sqrt(441 - (n << 3))) / 2 & 1;
    }
};