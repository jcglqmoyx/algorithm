#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        auto dfs = [&](auto &&dfs, int l, int r) -> vector<int> {
            vector<int> res;
            bool flag = true;
            for (int i = l; i <= r; i++) {
                if (!isdigit(expression[i])) {
                    auto left = dfs(dfs, l, i - 1), right = dfs(dfs, i + 1, r);
                    for (int x: left) {
                        for (int y: right) {
                            if (expression[i] == '+') {
                                res.emplace_back(x + y);
                            } else if (expression[i] == '-') {
                                res.emplace_back(x - y);
                            } else {
                                res.emplace_back(x * y);
                            }
                        }
                    }
                }
            }
            if (res.empty()) {
                return {stoi(expression.substr(l, r - l + 1))};
            }
            return res;
        };
        return dfs(dfs, 0, expression.size() - 1);
    }
};