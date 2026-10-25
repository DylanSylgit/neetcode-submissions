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
using namespace std;
#include <queue>
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) {return ans;}

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> currLvl;
            currLvl.reserve(size);

            for (int i = 0; i < size; i ++) {
                TreeNode* n = q.front();
                int val = n->val;
                q.pop();
                currLvl.push_back(val);

                if (n->left) {q.push(n->left);}
                if (n->right) {q.push(n->right);}
            }

            ans.push_back(std::move(currLvl));
        }

        return ans;


    }
};
