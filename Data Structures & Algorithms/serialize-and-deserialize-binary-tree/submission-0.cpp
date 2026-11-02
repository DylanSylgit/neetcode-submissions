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
#include <iostream>
#include <string>
#include <sstream>
#include <queue>
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        TreeNode* curr = root;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int si = q.size();
            for (unsigned int i = 0; i < si; i++) {
                TreeNode* t = q.front();
                q.pop();
                if (!t) {res+= "x,";}
                else {
                    res += std::to_string(t->val) + ",";
                    q.push(t->left);
                    q.push(t->right);
                }
 
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty() or data == "x"){
            return nullptr;
        }
        std::stringstream ss(data);
        string token;

        std::getline(ss,token,',');
        if (token == "x") return nullptr;
        TreeNode* r = new TreeNode(std::stoi(token));
        queue<TreeNode*> q;
        q.push(r);

        while(!q.empty()) {
            TreeNode* p = q.front();
            q.pop();

            if (std::getline(ss,token,',')) {
                if (token != "x") {
                    p->left = new TreeNode(stoi(token));
                    q.push(p->left);
                }
            }
            if (std::getline(ss,token,',')) {
                if (token != "x") {
                    p->right = new TreeNode(stoi(token));
                    q.push(p->right);
                }
            }
        }
        return r;

    }
    
};
