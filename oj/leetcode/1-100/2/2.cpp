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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(-1), head = dummy;
        int carry = 0;
        while (l1 || l2) {
            int s = carry;
            if (l1) s += l1->val, l1 = l1->next;
            if (l2) s += l2->val, l2 = l2->next;
            head->next = new ListNode(s % 10);
            head = head->next;
            carry = s / 10;
        }
        if (carry) head->next = new ListNode(carry);
        const auto sum = dummy->next;
        delete dummy;
        return sum;
    }
};
