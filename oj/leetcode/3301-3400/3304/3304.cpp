class Solution {
public:
    char kthCharacter(int k) {
        int change = 0;
        auto get = [&](auto &&get) -> char {
            if (k == 1) return change % 26 + 'a';
            int t = 1;
            while ((t << 1) < k) {
                t <<= 1;
            }
            change++;
            k -= t;
            return get(get);
        };
        return get(get);
    }
};