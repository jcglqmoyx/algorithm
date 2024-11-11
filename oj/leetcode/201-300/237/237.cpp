#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode *node) {
        auto ne = node->next;
        node->val = ne->val;
        node->next = ne->next;
        delete ne;
    }
};