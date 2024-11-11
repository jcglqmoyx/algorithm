#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size(), u = 0;
        function<bool(void)> dfs = [&]() -> bool {
            if (u >= n) return false;
            if (preorder[u] == '#') {
                u++;
                return true;
            }
            while (u < n && isdigit(preorder[u])) u++;
            u++;
            auto l = dfs();
            if (!l) return false;
            u++;
            auto r = dfs();
            if (!r) return false;
            return true;
        };
        return dfs() && u == n;
    }
};