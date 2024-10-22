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
    long long kthLargestLevelSum(TreeNode *root, int k) {
        queue<TreeNode *> q;
        q.emplace(root);
        vector<long long> v;
        while (!q.empty()) {
            long long s = 0;
            for (auto it = q.size(); it; it--) {
                auto t = q.front();
                q.pop();
                s += t->val;
                if (t->left) q.emplace(t->left);
                if (t->right) q.emplace(t->right);
            }
            v.emplace_back(s);
        }
        if (v.size() < k) return -1;
        nth_element(v.begin(), v.begin() + k - 1, v.end(), greater<>());
        return v[k - 1];
    }
};