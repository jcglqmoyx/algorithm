#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode* next) : val(x), next(next) {
    }
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        auto curr = list1;
        for (int i = 1; i < a; i++) curr = curr->next;
        for (int i = a; i <= b; i++) curr->next = curr->next->next;
        auto tmp = curr->next;
        curr->next = list2;
        while (list2->next) list2 = list2->next;
        list2->next = tmp;
        return list1;
    }
};
