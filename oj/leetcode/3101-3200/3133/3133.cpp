class Solution {
public:
    long long minEnd(int n, int x) {
        n--;
        long long ans = x;
        int i = 0, j = 0;
        while (n >> j) {
            if ((ans >> i & 1) == 0) {
                ans |= (long long) (n >> j & 1) << i;
                j++;
            }
            i++;
        }
        return ans;
    }
};