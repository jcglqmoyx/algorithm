int c2(int n) {
    return n > 1 ? n * (n - 1) / 2 : 0;
}

class Solution {
public:
    int distributeCandies(int n, int limit) {
        return c2(n + 2) - 3 * c2(n - limit + 1) + 3 * c2(n - 2 * limit) - c2(n - 3 * limit - 1);
    }
};