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

const int N = 100010;

int h[N], e[N << 1], ne[N << 1], idx;
int max_dist = 0;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs1(TreeNode *node, int parent) {
    if (!node) return;
    if (parent != -1) {
        add(node->val, parent);
        add(parent, node->val);
    }
    dfs1(node->left, node->val);
    dfs1(node->right, node->val);
}

void dfs2(int u, int p, int dist) {
    max_dist = max(max_dist, dist);
    for (int i = h[u]; ~i; i = ne[i]) {
        if (e[i] == p) continue;
        dfs2(e[i], u, dist + 1);
    }
}

class Solution {
public:
    int amountOfTime(TreeNode *root, int start) {
        memset(h, -1, sizeof h), idx = 0, max_dist = 0;
        dfs1(root, -1);
        if (idx == 0) return 0;
        dfs2(start, -1, 0);
        return max_dist;
    }
};