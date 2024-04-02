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
    vector<TreeNode *> allPossibleFBT(int n) {
        function<vector<TreeNode *>(int)> dfs = [&](int tot) -> vector<TreeNode *> {
            vector<TreeNode *> res;
            if (tot == 1) {
                res.emplace_back(new TreeNode());
            } else {
                for (int l = 1; l < tot - 1; l += 2) {
                    auto left = dfs(l);
                    auto right = dfs(tot - 1 - l);
                    for (auto x: left) {
                        for (auto y: right) {
                            auto root = new TreeNode();
                            root->left = x;
                            root->right = y;
                            res.emplace_back(root);
                        }
                    }
                }
            }
            return res;
        };
        return dfs(n);
    }
};