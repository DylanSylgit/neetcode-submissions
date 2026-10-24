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

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lowestNode = (p->val < q->val) ? p : q;
        TreeNode* highestNode = (p->val > q->val) ? p : q;
        TreeNode* ret = nullptr;

        findLowest(root,lowestNode,highestNode,ret);


        return ret;

    }
    void findLowest(TreeNode* root, TreeNode* lowest, TreeNode* highest, TreeNode*& ret) {

        if (!root){
            return;
        }

        if (highest->val < root->val) {
            findLowest(root->left,lowest,highest,ret);
            return;
        }

        if (lowest->val > root->val) {
            findLowest(root->right,lowest,highest,ret);
            return;
        }

        TreeNode* left = root->left;

        if (left and (left->val < lowest->val)) {
            return;
        }
        ret = root;

    }
};
