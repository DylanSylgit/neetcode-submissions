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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (!root) {return ans;}
        idk(root,0,ans);

        return ans;
    }

    void idk(TreeNode* curr, int level, vector<vector<int>>& ans) {
        if (!curr) {return;}
        if (level == ans.size()) {
            ans.push_back({});
        }
        ans[level].push_back(curr->val);
        if (curr->left) {idk(curr->left,level + 1, ans);}
        if (curr->right) {idk(curr->right,level + 1, ans);}

    }
};
