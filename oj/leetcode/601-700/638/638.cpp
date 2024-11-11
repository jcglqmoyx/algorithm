#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs) {
        auto n = price.size();
        vector<vector<int>> special_offer;
        for (auto &offer: special) {
            int tot = 0;
            for (int i = 0; i < n; i++) {
                tot += price[i] * offer[i];
            }
            if (tot > offer[n]) {
                special_offer.emplace_back(offer);
            }
        }
        map<vector<int>, int> memo;
        auto dp = [&](auto &&dp, vector<int> needs) {
            if (memo.contains(needs)) {
                return memo[needs];
            }
            int res = 0;
            for (int i = 0; i < n; i++) {
                res += price[i] * needs[i];
            }
            for (auto &offer: special_offer) {
                vector<int> t;
                for (int i = 0; i < n; i++) {
                    if (offer[i] > needs[i]) {
                        break;
                    }
                    t.emplace_back(needs[i] - offer[i]);
                }
                if (t.size() == n) {
                    res = min(res, dp(dp, t) + offer[n]);
                }
            }
            memo[needs] = res;
            return res;
        };
        return dp(dp, needs);
    }
};