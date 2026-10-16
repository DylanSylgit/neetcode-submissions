/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {return nullptr;}

        Node* curr = head;
        while(curr){ 
            Node* clone = new Node(curr->val);
            clone->next = curr->next;
            curr->next = clone;
            curr = clone->next;
        }

        curr = head;
        while(curr) {
            if(curr->random){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        Node* dummy = new Node(0);
        Node* copyCur = dummy;
        curr = head;

        while (curr) {
            Node* clone = curr->next;
            curr->next = clone->next;

            copyCur->next = clone;
            copyCur = clone;

            curr = curr->next;
        }

        Node* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};
