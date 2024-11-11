#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>> &meetings) {
        sort(meetings.begin(), meetings.end(), [](auto &a, auto &b) {
            return a[0] < b[0];
        });
        for (int i = 0; i < meetings.size(); i++) {
            int start = meetings[i][0];
            int end = meetings[i][1];
            while (i + 1 < meetings.size() && meetings[i + 1][0] <= end) {
                end = max(end, meetings[i + 1][1]);
                i++;
            }
            days -= end - start + 1;
        }
        return days;
    }
};