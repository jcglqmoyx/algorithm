#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string fractionAddition(string expression) {
        if (expression[0] != '-') {
            expression = "+" + expression;
        }
        auto n = expression.size();
        auto calc = [](int a, int b, int c, int d, char op) {
            return pair<int, int>{(op == '+' ? a * d + b * c : a * d - b * c), b * d};
        };
        int a = 0, b = 1;
        for (int i = 0; i < n; i++) {
            char op = expression[i];
            i++;
            int c = 0, d = 0;
            while (expression[i] != '/') {
                c = c * 10 + expression[i] - '0';
                i++;
            }
            i++;
            while (i < n && isdigit(expression[i])) {
                d = d * 10 + expression[i] - '0';
                i++;
            }
            i--;
            auto t = calc(a, b, c, d, op);
            a = t.first, b = t.second;
        }
        if (a == 0) b = 1;
        int g = gcd(a, b);
        a /= g, b /= g;
        return to_string(a) + "/" + to_string(b);
    }
};