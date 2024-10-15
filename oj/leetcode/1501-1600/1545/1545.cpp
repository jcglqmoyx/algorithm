class Solution {
public:
    char findKthBit(int n, int k) {
        int len = (1 << n) - 1;
        int invert = 0;
        while (len) {
            int half = len / 2;
            if (k > half + 1) k = 1 + len - k, invert++;
            len = half;
        }
        return invert % 2 + '0';
    }
};