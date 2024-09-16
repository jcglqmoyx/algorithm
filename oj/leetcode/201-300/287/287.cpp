#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int cur = 0;
        while (true) {
            const int ne = nums[cur];
            if (ne < 0) return cur;
            nums[cur] = -1;
            cur = ne;
        }
    }
};
