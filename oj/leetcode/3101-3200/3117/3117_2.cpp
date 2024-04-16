#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

class Queue {
    int s1[10001]{}, s2[10001]{}, idx1{}, idx2{};
    vector<int> &nums;

public:
    Queue(vector<int> &nums) : nums(nums) {
        s1[0] = s2[0] = -1;
    }

    int sum() {
        return s1[idx1] & s2[idx2];
    }

    int size() const {
        return idx1 + idx2;
    }

    void push(int x) {
        s2[idx2 + 1] = s2[idx2] & x;
        idx2++;
    }

    void pop(int u) {
        if (!idx1) {
            idx1 = (idx2 + 1) >> 1;
            for (int i = 1; i <= idx1; i++) {
                s1[i] = s1[i - 1] & nums[u - idx2 + idx1 + 1 - i];
            }
            idx2 -= idx1;
            for (int i = 1; i <= idx2; i++) {
                s2[i] = s2[i - 1] & nums[u - idx2 + i];
            }
        }
        idx1--;
    }
};


class Solution {
public:
    int minimumValueSum(vector<int> &nums, const vector<int> &andValues) {
        auto n = nums.size();
        int f[n + 1], g[n + 1];
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (int e: andValues) {
            Queue q1(nums), q2(nums);
            int min_sum = INF;
            memset(g, 0x3f, sizeof g);
            for (int i = 0; i < n; ++i) {
                q1.push(nums[i]);
                q2.push(nums[i]);
                if (q1.sum() < e) {
                    min_sum = INF;
                    while (q1.size() && q1.sum() < e) q1.pop(i);
                }
                while (q2.size() && q2.sum() < e) q2.pop(i);
                while (q2.size() && q2.sum() == e) {
                    min_sum = min(min_sum, f[i - q2.size() + 1]);
                    q2.pop(i);
                }
                g[i + 1] = min_sum + nums[i];
            }
            memcpy(f, g, sizeof g);
        }
        return f[n] >= INF ? -1 : f[n];
    }
};