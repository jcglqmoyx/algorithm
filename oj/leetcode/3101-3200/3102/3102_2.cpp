#include <bits/stdc++.h>

using namespace std;

class Solution {
    void update_max(int x, int &a, int &b) {
        if (x > b) {
            if (x > a) {
                b = a;
                a = x;
            } else {
                b = x;
            }
        }
    }

    void update_min(int x, int &a, int &b) {
        if (x < b) {
            if (x < a) {
                b = a;
                a = x;
            } else {
                b = x;
            }
        }
    }

public:
    int minimumDistance(vector<vector<int>> &points) {
        int max_x1 = -1e9, max_x2 = -1e9, max_y1 = -1e9, max_y2 = -1e9;
        int min_x1 = 1e9, min_x2 = 1e9, min_y1 = 1e9, min_y2 = 1e9;
        for (auto &p: points) {
            int x = p[0] - p[1];
            int y = p[0] + p[1];
            update_max(x, max_x1, max_x2);
            update_min(x, min_x1, min_x2);
            update_max(y, max_y1, max_y2);
            update_min(y, min_y1, min_y2);
        }
        int res = 1e9;
        for (auto &p: points) {
            int x = p[0] - p[1];
            int y = p[0] + p[1];
            int dx = (x == max_x1 ? max_x2 : max_x1) - (x == min_x1 ? min_x2 : min_x1);
            int dy = (y == max_y1 ? max_y2 : max_y1) - (y == min_y1 ? min_y2 : min_y1);
            res = min(res, max(dx, dy));
        }
        return res;
    }
};