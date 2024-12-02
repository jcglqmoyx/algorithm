#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems) {
        vector<vector<int>> g_group(m);
        vector<int> d_group(m);
        vector<vector<int>> group_elements(m);
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = m++;
                d_group.emplace_back(0);
                g_group.emplace_back();
                group_elements.emplace_back();
            }
        }
        for (int i = 0; i < n; i++) {
            for (int x: beforeItems[i]) {
                if (group[x] != group[i]) {
                    d_group[group[i]]++;
                    g_group[group[x]].emplace_back(group[i]);
                }
            }
        }
        int q[n * 2];
        int hh = 0, tt = -1;
        int group_path[m], idx = 0;
        for (int j = 0; j < m; j++) {
            if (d_group[j] == 0) {
                q[++tt] = j;
            }
        }
        while (hh <= tt) {
            int t = q[hh++];
            group_path[idx++] = t;
            for (int x: g_group[t]) {
                if (--d_group[x] == 0) {
                    q[++tt] = x;
                }
            }
        }
        if (idx != m) {
            return {};
        }
        vector<vector<int>> g_item(n);
        int d_item[n];
        memset(d_item, 0, sizeof d_item);
        for (int i = 0; i < n; i++) {
            for (int x: beforeItems[i]) {
                g_item[x].emplace_back(i);
                d_item[i]++;
            }
        }
        hh = 0, tt = -1;
        for (int i = 0; i < n; i++) {
            if (d_item[i] == 0) {
                q[++tt] = i;
            }
        }
        while (hh <= tt) {
            int t = q[hh++];
            group_elements[group[t]].emplace_back(t);
            for (int x: g_item[t]) {
                if (--d_item[x] == 0) {
                    q[++tt] = x;
                }
            }
        }
        vector<int> res;
        for (int i = 0; i < idx; i++) {
            for (int x: group_elements[group_path[i]]) {
                res.emplace_back(x);
            }
        }
        if (res.size() != n) {
            res.clear();
        }
        return res;
    }
};