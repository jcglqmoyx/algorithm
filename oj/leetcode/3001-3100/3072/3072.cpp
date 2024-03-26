#include <bits/stdc++.h>

using namespace std;

int low_bit(const int x) { return x & -x; }

class BinaryIndexTree {
public:
    int n;
    vector<int> tr;

    explicit BinaryIndexTree(const int n) {
        this->n = n;
        tr.resize(n + 1);
    }

    void update(int x) {
        while (x <= n) tr[x] += 1, x += low_bit(x);
    }

    int query(int x) {
        int res = 0;
        while (x) res += tr[x], x -= low_bit(x);
        return res;
    }
};

int greater_count(BinaryIndexTree&bit, vector<int>&arr, int x) {
    return arr.size() - bit.query(x);
}

class Solution {
public:
    vector<int> resultArray(vector<int>&nums) {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        auto get = [&](int x) {
            return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
        };
        int m = v.size();
        BinaryIndexTree bit1(m), bit2(m);
        vector<int> arr1, arr2;
        arr1.reserve(nums.size());
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        bit1.update(get(nums[0]));
        bit2.update(get(nums[1]));
        for (int i = 2; i < nums.size(); i++) {
            int p = get(nums[i]);
            int x = greater_count(bit1, arr1, p);
            int y = greater_count(bit2, arr2, p);
            if (x > y) arr1.push_back(nums[i]), bit1.update(p);
            else if (x < y) arr2.push_back(nums[i]), bit2.update(p);
            else {
                if (arr1.size() <= arr2.size()) arr1.push_back(nums[i]), bit1.update(p);
                else arr2.push_back(nums[i]), bit2.update(p);
            }
        }
        for (int x: arr2) arr1.push_back(x);
        return arr1;
    }
};
