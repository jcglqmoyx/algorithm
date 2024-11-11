#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        int n = 0;
        for (auto cur = head; cur; cur = cur->next) {
            n++;
        }
        int sub = n / k, mod = n % k;
        vector<ListNode *> res(k);
        for (int i = 0; i < k; i++) {
            res[i] = head;
            if (sub || mod) {
                for (int it = 0; it < sub + (mod ? 1 : 0) - 1; it++) {
                    head = head->next;
                }
                auto next = head->next;
                head->next = nullptr;
                head = next;
                if (mod) mod--;
            }
        }
        return res;
    }
};