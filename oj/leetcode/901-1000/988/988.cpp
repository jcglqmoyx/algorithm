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
    string res;

    void dfs(TreeNode *node, string &s) {
        if (!node) return;
        s += (node->val + 'a');
        if (!node->left && !node->right) {
            string t = s;
            reverse(t.begin(), t.end());
            if (res.empty() || res > t) res = t;
        }
        dfs(node->left, s);
        dfs(node->right, s);
        s.pop_back();
    }

public:
    string smallestFromLeaf(TreeNode *root) {
        string s;
        dfs(root, s);
        return res;
    }
};
