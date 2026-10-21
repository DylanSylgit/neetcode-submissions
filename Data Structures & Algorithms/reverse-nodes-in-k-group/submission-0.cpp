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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Maybe two pointers?
        ListNode* slow = head;
        ListNode* ret = head;
        ListNode* prevGroupTail = nullptr;
        bool first = true;

        while (slow) {
            ListNode* fast = slow;
            for (int i = 0; i < k-1 and fast!=nullptr; i++) {
                fast = fast->next;
            }
            if (!fast) {
                if (prevGroupTail) {
                    prevGroupTail->next = slow;
                }
                break;
            }

            ListNode* nxt = fast->next;

            ListNode* newHead = reverse(slow,k);
            if (first) {
                ret = newHead;
                first = false;
            }

            if (prevGroupTail) {
                prevGroupTail->next = newHead;
            }
            prevGroupTail = slow;
            slow = nxt;
            
        }
        return ret;
        
    }
    ListNode* reverse(ListNode* head, int k){
        ListNode* prev = nullptr;
        ListNode* curr = head;

        for (int i = 0; i < k; i++) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
};
