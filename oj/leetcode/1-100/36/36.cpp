#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        int row[9]{}, col[9]{}, box[3][3]{};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int x = board[i][j] - '0';
                    if (row[i] >> x & 1 || col[j] >> x & 1 || box[i / 3][j / 3] >> x & 1) {
                        return false;
                    }
                    row[i] |= 1 << x;
                    col[j] |= 1 << x;
                    box[i / 3][j / 3] |= 1 << x;
                }
            }
        }
        return true;
    }
};