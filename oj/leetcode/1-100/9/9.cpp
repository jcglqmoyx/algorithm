class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || x && x % 10 == 0) return false;
        int r = 0;
        while (x > r) {
            r = r * 10 + x % 10;
            x /= 10;
        }
        return x == r || r / 10 == x;
    }
};