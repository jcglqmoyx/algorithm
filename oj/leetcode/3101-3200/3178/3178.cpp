class Solution {
public:
    int numberOfChild(int n, int k) {
        int period = (n - 1) << 1;
        k %= period;
        if (k < n) return k;
        return n * 2 - 2 - k;
    }
};