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
using namespace std;
#include <iostream>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0 ){
            return nullptr;
        }

        while (lists.size() > 1){
            vector<ListNode*> merged;

            for(int i = 0; i < lists.size(); i+=2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = nullptr;
                if (i+1 < lists.size()){
                    l2 = lists[i+1];
                }
                merged.push_back(mergeTwoLists(l1,l2));
            }
            lists = std::move(merged);
        }
        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l2) {
            return l1;
        }
        if (!l1) {
            return l2;
        }
        ListNode* head = nullptr;
        if (l1->val < l2-> val) {
            head = l1;
            l1 = l1->next;
        }
        else {
            head = l2;
            l2 = l2->next;
        }
        ListNode* curr = head;
        while (l1 and l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if (l1){
            curr->next = l1;
        }
        if (l2) {
            curr->next = l2;
        }
        return head;
    }
};
