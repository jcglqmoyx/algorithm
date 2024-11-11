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

int moves;

class Solution {
    /*
     * amount of nodes, amount of coins
     */
    pair<int, int> dfs(TreeNode *node) {
        if (!node) return {};
        auto l = dfs(node->left), r = dfs(node->right);
        moves += abs((l.first - l.second)) + abs((r.first - r.second));
        return {l.first + r.first + 1, l.second + r.second + node->val};
    }

public:
    int distributeCoins(TreeNode *root) {
        moves = 0;
        dfs(root);
        return moves;
    }
};
