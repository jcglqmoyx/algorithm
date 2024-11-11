#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int n = s.size(), steps = 0;
        int carry = 0;
        for (int i = n - 1; i >= 1; i--) {
            steps++;
            if (s[i] == '0') {
                if (carry) {
                    steps++;
                }
            } else {
                if (!carry) {
                    carry = 1;
                    steps++;
                }
            }
        }
        if (carry) steps++;
        return steps;
    }
};