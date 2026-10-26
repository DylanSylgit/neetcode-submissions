/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (!root) {return ret;}
        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {

            int size = q.size();

            for (int i = 1; i < size; i++) {
                TreeNode* tmp = q.front();
                if (tmp->left) {q.push(tmp->left);}
                if (tmp->right) {q.push(tmp->right);}
                q.pop(); 
            }
            TreeNode* n = q.front();
            ret.push_back(n->val);
            if (n->left) {q.push(n->left);}
            if (n->right) {q.push(n->right);}
            q.pop();

        }
        return ret;
    }
};
