struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode *reverse(ListNode *node) {
        ListNode *prev = nullptr;
        while (node) {
            auto ne = node->next;
            node->next = prev;
            prev = node;
            node = ne;
        }
        return prev;
    }

public:
    ListNode *doubleIt(ListNode *head) {
        head = reverse(head);
        int carry = 0;
        auto backup = head;
        while (head) {
            int s = head->val * 2 + carry;
            head->val = s % 10;
            carry = s / 10;
            if (carry && !head->next) {
                head->next = new ListNode(carry);
                break;
            } else {
                head = head->next;
            }
        }
        return reverse(backup);
    }
};