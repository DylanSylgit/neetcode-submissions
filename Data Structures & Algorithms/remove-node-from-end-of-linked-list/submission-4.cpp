/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        for (int i = 0; i < n-1; i++) {
            fast = fast->next;
        }

        while(fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if (prev) {prev->next = slow->next;}
        if (slow == head) {
            head = slow->next;
        }
        slow->next = nullptr;

        return head;
    }
};
