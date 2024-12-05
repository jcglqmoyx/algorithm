int min(int x, int y) {
    return x < y ? x : y;
}

int max(int x, int y) {
    return x > y ? x : y;
}

int abs(int x) {
    return x >= 0 ? x : -x;
}

class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        int res = 2;
        if (a == e) {
            int mn = min(b, f);
            int mx = max(b, f);
            if (c != a || d < mn || d > mx) {
                res = 1;
            }
        }
        if (b == f) {
            int mn = min(a, e);
            int mx = max(a, e);
            if (d != b || c < mn || c > mx) {
                res = 1;
            }
        }
        if (abs(e - c) == abs(f - d)) {
            if (abs(c - a) != abs(d - b) || abs(e - a) != abs(f - b) || abs(c - a) + abs(e - a) != abs(e - c)) {
                res = 1;
            }
        }
        return res;
    }
};