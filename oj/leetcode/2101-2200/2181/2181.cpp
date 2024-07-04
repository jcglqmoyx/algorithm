struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeNodes(ListNode *head) {
        while (head->val == 0) {
            head = head->next;
        }
        auto res = head;
        while (head) {
            auto t = head;
            int val = 0;
            while (t->val) {
                val += t->val;
                t = t->next;
            }
            head->val = val;
            head->next = t->next;
            head = head->next;
        }
        return res;
    }
};