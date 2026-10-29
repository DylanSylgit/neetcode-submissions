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
        vector<TreeNode*> st;
        TreeNode* curr = root;

        while (curr or !st.empty()) {
            while(curr) {
                st.push_back(curr);
                curr = curr->left;
            }
            curr = st.back();
            st.pop_back();

            if (--k == 0) {
                return curr->val;
            }

            curr = curr->right;
        }
        return -1;
    }
};
