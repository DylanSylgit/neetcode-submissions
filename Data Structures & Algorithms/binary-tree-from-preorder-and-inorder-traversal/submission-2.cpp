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
#include <unordered_map>
class Solution {
private:
    unordered_map<int,int> m;
    vector<int> preorder;
    vector<int> inorder;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this-> preorder = std::move(preorder);
        this-> inorder = std::move(inorder);

        for (unsigned int i =0; i < this->inorder.size(); i++) {
            m[this->inorder[i]] = i;
        }
        int pre = 0;

        return build(pre,0,this->preorder.size()-1);

    }
    TreeNode* build(int& pre, int l, int r) {
        if (l > r) {return nullptr;}

        int val = preorder[pre++];
        TreeNode* root = new TreeNode(val);

        int mid = m.at(val);

        root->left = build(pre,l, mid-1);
        root->right = build(pre, mid+1, r);

        return root;
    }
};
