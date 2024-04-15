struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int sum;

    void dfs(TreeNode *node, int x) {
        x = x * 10 + node->val;
        if (!node->left && !node->right) sum += x;
        if (node->left) dfs(node->left, x);
        if (node->right) dfs(node->right, x);
    }

public:
    int sumNumbers(TreeNode *root) {
        sum = 0;
        dfs(root, 0);
        return sum;
    }
};
