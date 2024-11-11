#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        if (cloned == nullptr || cloned->val == target->val) return cloned;
        auto l = getTargetCopy(original, cloned->left, target);
        if (l) return l;
        return getTargetCopy(original, cloned->right, target);
    }
};