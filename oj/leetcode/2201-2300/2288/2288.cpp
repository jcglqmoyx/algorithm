#include <bits/stdc++.h>

using namespace std;

string double_to_string(double number, int precision) {
    ostringstream out;
    out << fixed << setprecision(precision) << number;
    return out.str();
}

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        stringstream ss(sentence);
        string word;
        string res;
        while (ss >> word) {
            if (word[0] == '$') {
                bool ok = true;
                long long p = 0;
                for (int i = 1; i < word.size(); i++) {
                    if (!isdigit(word[i])) {
                        ok = false;
                        break;
                    }
                    p = p * 10 + word[i] - '0';
                }
                if (ok && word.size() != 1) {
                    res += "$" + double_to_string(p - p * discount * 1.0 / 100, 2) + " ";
                } else {
                    res += word + " ";
                }
            } else {
                res += word + " ";
            }
        }
        res.pop_back();
        return res;
    }
};