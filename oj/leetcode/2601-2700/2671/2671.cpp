#include <bits/stdc++.h>

using namespace std;

class FrequencyTracker {
    unordered_map<int, int> cnt, freq;

public:
    FrequencyTracker() {
    }

    void add(int number) {
        cnt[number]++;
        freq[cnt[number]]++;
        if (cnt[number] > 1) {
            freq[cnt[number] - 1]--;
            if (freq[cnt[number] - 1] == 0) {
                freq.erase(cnt[number] - 1);
            }
        }
    }

    void deleteOne(int number) {
        if (cnt.contains(number)) {
            cnt[number]--;
            if (cnt[number] == 0) {
                cnt.erase(number);
                freq[1]--;
                if (freq[1] == 0) {
                    freq.erase(1);
                }
            } else {
                freq[cnt[number]]++;
                freq[cnt[number] + 1]--;
                if (freq[cnt[number] + 1] == 0) {
                    freq.erase(cnt[number] + 1);
                }
            }
        }
    }

    bool hasFrequency(int frequency) {
        return freq.contains(frequency);
    }
};
