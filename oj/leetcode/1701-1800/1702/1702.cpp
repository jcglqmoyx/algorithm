#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string maximumBinaryString(string binary) {
        auto n = binary.size();
        for (int i = 0, last = -1; i < n; i++) {
            if (binary[i] == '0') {
                if (last == -1) {
                    last = i;
                } else {
                    binary[i] = '1';
                    binary[last] = '1', binary[last + 1] = '0';
                    last++;
                }
            }
        }
        return binary;
    }
};