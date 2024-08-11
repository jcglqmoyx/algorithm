#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string> &commands) {
        int x = 0, y = 0;
        for (auto &c: commands) {
            switch (c[0]) {
                case 'R':
                    y++;
                    break;
                case 'D':
                    x++;
                    break;
                case 'L':
                    y--;
                    break;
                default:
                    x--;
            }
        }
        return x * n + y;
    }
};