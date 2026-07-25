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
    void infun(vector<int>&v , TreeNode * root){
        if(root == NULL)return ;
        infun(v,root->left);
        v.push_back(root->val);
        infun(v,root->right);
        
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        infun(v,root);
        return v;
    }
};