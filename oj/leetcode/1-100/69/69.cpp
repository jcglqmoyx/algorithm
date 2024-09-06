class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while (l < r) {
            long long mid = (l + r + 1LL) >> 1;
            if (mid * mid <= x) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};