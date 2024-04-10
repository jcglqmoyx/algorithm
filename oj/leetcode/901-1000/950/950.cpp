#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck) {
        sort(deck.begin(), deck.end());
        auto n = deck.size();
        vector<int> res(n);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            q.emplace(i);
        }
        int idx = 0;
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            res[t] = deck[idx++];
            if (!q.empty()) {
                q.emplace(q.front());
                q.pop();
            }
        }
        return res;
    }
};