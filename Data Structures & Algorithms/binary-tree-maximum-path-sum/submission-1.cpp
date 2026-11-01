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
        int res = root->val;
        dfs(root, res);
        return res;
    }
    int dfs(TreeNode* root, int& m) {
        if (!root) {return 0;}

        int lMax = max(dfs(root->left,m),0);
        int rMax = max(dfs(root->right,m),0);

        m = max(m,root->val + lMax + rMax);
        return root->val + max(lMax,rMax);
    }
};
