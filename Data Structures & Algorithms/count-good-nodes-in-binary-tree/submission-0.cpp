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
    int goodNodes(TreeNode* root) {
        int res = 0;
        find(root,-101,res);
        return res;
    }

    void find(TreeNode* n, int prev, int& res) {
        if (!n) {return;}

        int m = max(prev,n->val);

        if (n->val >= m) {
            res +=1;
        }

        find(n->left,m,res);
        find(n->right,m,res);

    }
};
