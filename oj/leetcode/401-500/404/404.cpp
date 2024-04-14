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
    int sumOfLeftLeaves(TreeNode *root) {
        pair<TreeNode *, bool> q[1010];
        int hh = 0, tt = -1;
        q[++tt] = {root, false};
        int res = 0;
        while (hh <= tt) {
            for (int size = tt - hh + 1; size; size--) {
                auto &[t, is_left] = q[hh++];
                if (!t->left && !t->right && is_left) res += t->val;
                if (t->left) q[++tt] = {t->left, true};
                if (t->right) q[++tt] = {t->right, false};
            }
        }
        return res;
    }
};