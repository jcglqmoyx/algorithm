#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        bool st[m][n];
        memset(st, 0, sizeof st);
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        for (int x = 0, y = 0, d = 0; head; head = head->next) {
            res[x][y] = head->val;
            st[x][y] = true;
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx == m || ny < 0 || ny == n || st[nx][ny]) {
                d = (d + 1) % 4;
                nx = x + dx[d], ny = y + dy[d];
            }
            x = nx, y = ny;
        }
        return res;
    }
};