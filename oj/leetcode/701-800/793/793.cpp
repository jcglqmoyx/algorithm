class Solution {
    long long get(long long x) {
        long long cnt = 0;
        for (long long p = 5; p <= x; p *= 5) {
            cnt += x / p;
        }
        return cnt;
    }

    long long binary_search(long long k) {
        long long l = 0, r = k * 5 + 10;
        while (l < r) {
            long long mid = (l + r + 1) >> 1;
            if (get(mid) > k) r = mid - 1;
            else l = mid;
        }
        return l;
    }

public:
    int preimageSizeFZF(int k) {
        if (k == 0) return 5;
        auto a = binary_search(k);
        auto b = binary_search(k - 1);
        return a - b;
    }
};