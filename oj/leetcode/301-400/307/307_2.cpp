#include <bits/stdc++.h>

using namespace std;

const int N = 30010;

int n;
int tr[N];

int low_bit(int x) {
    return x & -x;
}

void modify(int x, int v) {
    while (x <= n) {
        tr[x] += v;
        x += low_bit(x);
    }
}

int ask(int x) {
    int res = 0;
    while (x) {
        res += tr[x];
        x -= low_bit(x);
    }
    return res;
}

class NumArray {
    vector<int> &v;
public:
    NumArray(vector<int> &nums) : v(nums) {
        n = (int) nums.size();
        memset(tr, 0, sizeof(int) * (n + 1));
        for (int i = 1; i <= n; i++) {
            modify(i, nums[i - 1]);
        }
    }

    void update(int index, int val) {
        modify(index + 1, val - v[index]);
        v[index] = val;
    }

    int sumRange(int left, int right) {
        return ask(right + 1) - ask(left);
    }
};