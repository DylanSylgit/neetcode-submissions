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

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    Node* copyRandomList(Node* head){

        unordered_map<Node*,Node*> seen;
        
        auto getClone = [&](Node* n) -> Node* {
            if (!n) {
                return nullptr;
            }
            if (seen.count(n)){
                return seen[n];
            }

            seen[n] = new Node(n->val);
            return seen[n];
        };

        Node* curr = head;
        while (curr) {
            Node* copy = getClone(curr);
            copy->next = getClone(curr->next);
            copy->random = getClone(curr->random);
            curr = curr->next;
        }

        return seen[head];
    }
};
