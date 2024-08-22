class Solution {
public:
    int findComplement(int num) {
        int bits = 32 - __builtin_clz(num);
        return (int) (~num & ((1LL << bits) - 1));
    }
};