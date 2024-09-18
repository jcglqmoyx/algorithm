#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        auto n = buses.size(), m = passengers.size();
        int j = 0;
        int left;
        for (int i = 0; i < n; i++) {
            left = capacity;
            while (left && j < m && passengers[j] <= buses[i]) {
                left--;
                j++;
            }
        }
        if (j == 0 || left && buses.back() != passengers[j - 1]) {
            return buses.back();
        }
        int time = 0;
        for (int i = j - 1; i >= 0; i--) {
            int x = passengers[i] - 1;
            if (i == 0 || passengers[i - 1] != x) {
                time = x;
                break;
            }
        }
        return time;
    }
};