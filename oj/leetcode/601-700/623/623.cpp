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
    TreeNode *addOneRow(TreeNode *root, int val, int depth) {
        if (depth == 1) {
            auto res = new TreeNode(val);
            res->left = root;
            return res;
        }
        queue<TreeNode *> q;
        q.emplace(root);
        int d = 1;
        while (!q.empty()) {
            if (d + 1 == depth) {
                for (auto it = q.size(); it; it--) {
                    auto t = q.front();
                    q.pop();
                    auto l = t->left, r = t->right;
                    t->left = new TreeNode(val), t->right = new TreeNode(val);
                    t->left->left = l;
                    t->right->right = r;
                }
                break;
            } else {
                for (auto it = q.size(); it; it--) {
                    auto t = q.front();
                    q.pop();
                    if (t->left) q.emplace(t->left);
                    if (t->right) q.emplace(t->right);
                }
            }
            d++;
        }
        return root;
    }
};