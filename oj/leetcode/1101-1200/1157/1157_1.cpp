#include <bits/stdc++.h>

using namespace std;

class MajorityChecker {
public:
    explicit MajorityChecker(vector<int>&arr): arr(arr) {
        for (int i = 0; i < arr.size(); i++) {
            location[arr[i]].push_back(i);
        }
    }

    int query(const int left, const int right, const int threshold) {
        const int length = right - left + 1;

        for (int i = 0; i < k; ++i) {
            int x = arr[rand(arr.size())];
            vector<int>&pos = location[x];
            const auto cnt = ranges::upper_bound(pos.begin(), pos.end(), right) - ranges::lower_bound(
                                 pos.begin(), pos.end(), left);
            if (cnt >= threshold) {
                return x;
            }
            if (cnt * 2 >= length) {
                return -1;
            }
        }

        return -1;
    }

private:
    static constexpr int k = 20;
    const vector<int>&arr;

    unordered_map<int, vector<int>> location;

    static int rand(auto max) {
        mt19937 gen(random_device{}());
        uniform_int_distribution<> distrib(0, max);
        return distrib(gen);
    }
};
