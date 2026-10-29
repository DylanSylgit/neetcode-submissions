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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        createVec(root,v);
        return v[k-1];
    }
    void createVec(TreeNode* r, vector<int>& v) {
        if (!r) {return;}
        createVec(r->left,v);
        
        v.push_back(r->val);

        createVec(r->right,v);
    }
};
