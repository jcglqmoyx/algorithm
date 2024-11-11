#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    static int maxAncestorDiff(TreeNode *root) {
        int res = 0;
        function<void(TreeNode *, int, int)> dfs = [&](TreeNode *node, int mn, int mx) {
            if (!node) return;
            if (mn != 1e9) res = max(res, abs(mn - node->val));
            if (mx != -1e9) res = max(res, abs(mx - node->val));
            int a = min(mn, node->val), b = max(mx, node->val);
            dfs(node->left, a, b);
            dfs(node->right, a, b);
        };
        dfs(root, 1e9, -1e9);
        return res;
    }
};