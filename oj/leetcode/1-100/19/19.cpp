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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int len = 0;
        for (auto cur = head; cur; cur = cur->next, len++);
        if (n == len) return head->next;
        auto cur = head;
        for (int _ = 0; _ + 1 < len - n; _++) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        return head;
    }
};