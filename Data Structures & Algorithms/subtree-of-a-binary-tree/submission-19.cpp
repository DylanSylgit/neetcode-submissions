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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {return false;}

        if (isSameTree(root,subRoot)) {return true;}

        return isSubtree(root->right,subRoot) or isSubtree(root->left, subRoot);
        
    }
private:
    bool isSameTree(TreeNode* root, TreeNode* subRoot) {
        if (!root and !subRoot) {return true;}

        if (!root or !subRoot or root->val != subRoot->val) {
            return false;
        }

        return isSameTree(root->left,subRoot->left) and isSameTree(root->right,subRoot->right);

    }
};
