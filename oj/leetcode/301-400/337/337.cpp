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


pair<int, int> dfs(TreeNode *node) {
    if (!node) return {0, 0};
    auto l = dfs(node->left);
    auto r = dfs(node->right);
    return {node->val + l.second + r.second, max(l.first, l.second) + max(r.first, r.second)};
};

class Solution {
public:
    int rob(TreeNode *root) {
        auto t = dfs(root);
        return max(t.first, t.second);
    }
};