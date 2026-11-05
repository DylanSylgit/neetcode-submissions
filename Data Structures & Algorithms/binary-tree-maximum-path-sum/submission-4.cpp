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
    int maxPathSum(TreeNode* root) {
        int ret = root->val;
        dfs(root,ret);
        return ret;

    }
    int dfs(TreeNode*root, int& ret ){
        if (!root) {return 0;}

        int maxL = max(dfs(root->left,ret),0);
        int maxR = max(dfs(root->right,ret),0);

        ret = max(root->val + maxL + maxR, ret);

        return root->val + max(maxL,maxR);
    }
};
