#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>> &board) {
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                if (board[x][y] == 'R') {
                    int cnt = 0;
                    for (int i = 0; i < 4; i++) {
                        int nx = x, ny = y;
                        while (true) {
                            nx += dx[i], ny += dy[i];
                            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
                                if (board[nx][ny] == 'p') {
                                    cnt++;
                                    break;
                                } else if (board[nx][ny] == 'B') {
                                    break;
                                }
                            } else {
                                break;
                            }
                        }
                    }
                    return cnt;
                }
            }
        }
        return 0;
    }
};