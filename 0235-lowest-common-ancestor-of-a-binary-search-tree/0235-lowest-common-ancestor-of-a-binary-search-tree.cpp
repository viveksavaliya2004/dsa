/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
TreeNode* finalnode =NULL;
    int fun(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL){
            return 0;
        }
        int left = fun(root->left , p ,q);
        int right = fun(root->right,p,q);
        int self = 0;
        if(root==p || root==q){
            self = 1;
        }
        int total = self + left + right;
        if(total == 2 && finalnode==NULL){
            finalnode = root;
        }
        return total;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return NULL;
        int ans = fun(root , p ,q);
        return finalnode;
    }
};