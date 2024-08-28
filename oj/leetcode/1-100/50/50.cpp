class Solution {
public:
    double power(double x, long n) {
        double res = 1.0;
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    double myPow(double x, int n) {
        return n > 0 ? power(x, (long) n) : 1 / power(x, -(long) n);
    }
};