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
    TreeNode *replaceValueInTree(TreeNode *root) {
        vector<int> v;
        queue<TreeNode *> q;
        q.emplace(root);
        unordered_map<TreeNode *, int> val;
        while (!q.empty()) {
            int s = 0;
            for (auto it = q.size(); it; it--) {
                auto t = q.front();
                q.pop();
                s += t->val;
                if (t->left) {
                    q.emplace(t->left);
                    val[t->left] = t->left->val;
                }
                if (t->right) {
                    q.emplace(t->right);
                }
            }
            v.emplace_back(s);
        }
        q.emplace(root);
        root->val = 0;
        int level = 0;
        while (!q.empty()) {
            level++;
            for (auto it = q.size(); it; it--) {
                auto t = q.front();
                q.pop();
                if (t->left) {
                    q.emplace(t->left);
                    t->left->val = v[level] - t->left->val;
                    if (t->right) t->left->val -= t->right->val;
                }
                if (t->right) {
                    q.emplace(t->right);
                    t->right->val = v[level] - t->right->val;
                    if (t->left) t->right->val -= val[t->left];
                }
            }
        }
        return root;
    }
};