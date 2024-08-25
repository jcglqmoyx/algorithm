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
    vector<int> v;

    void dfs(TreeNode *node) {
        if (!node) return;
        dfs(node->left);
        dfs(node->right);
        v.emplace_back(node->val);
    }

public:
    vector<int> postorderTraversal(TreeNode *root) {
        dfs(root);
        return v;
    }
};