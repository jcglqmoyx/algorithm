class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int t = x, s = 0;
        while (t) s += t % 10, t /= 10;
        return x % s ? -1 : s;
    }
};