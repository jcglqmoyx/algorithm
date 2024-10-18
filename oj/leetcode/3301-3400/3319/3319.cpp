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

    int dfs(TreeNode *node) {
        if (!node) return 0;
        auto l = dfs(node->left);
        auto r = dfs(node->right);
        if (l == -1 || l != r) {
            return -1;
        }
        v.emplace_back(l + r + 1);
        return l + r + 1;
    }

public:
    int kthLargestPerfectSubtree(TreeNode *root, int k) {
        dfs(root);
        if (v.size() < k) return -1;
        nth_element(v.begin(), v.begin() + k - 1, v.end(), greater<>());
        return v[k - 1];
    }
};