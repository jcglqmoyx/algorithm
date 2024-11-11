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
    vector<int> treeQueries(TreeNode *root, vector<int> &queries) {
        auto m = queries.size();
        int l[100010]{}, r[100010]{};
        int mx = 0;
        auto dfs1 = [&](auto dfs1, TreeNode *node, int depth) {
            if (!node) return;
            l[node->val] = mx;
            mx = max(mx, depth);
            dfs1(dfs1, node->left, depth + 1);
            dfs1(dfs1, node->right, depth + 1);
        };
        auto dfs2 = [&](auto dfs2, TreeNode *node, int depth) {
            if (!node) return;
            r[node->val] = mx;
            mx = max(mx, depth);
            dfs2(dfs2, node->right, depth + 1);
            dfs2(dfs2, node->left, depth + 1);
        };
        dfs1(dfs1, root, 0);
        mx = 0;
        dfs2(dfs2, root, 0);
        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            res[i] = max(l[queries[i]], r[queries[i]]);
        }
        return res;
    }
};