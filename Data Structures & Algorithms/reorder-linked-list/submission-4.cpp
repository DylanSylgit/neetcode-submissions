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
    void reorderList(ListNode* head) {
        ListNode* begin = head;
        ListNode* end = head;

        while (true) {
            while (end->next != nullptr and end->next->next != begin){
                end = end->next;
            }
            ListNode* tmp = begin->next;
            if (end->next == tmp) {
                end->next = nullptr;
                return;
            }
            begin->next = end;
            end->next = tmp;
            begin = tmp;
            end = begin;
        }

    }
};
