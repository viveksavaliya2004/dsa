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
int hight(TreeNode*r1 , bool &valid){
        if(!r1){
            return 0;
        }
        
        int lh =hight(r1->left , valid);
        int rh =hight(r1->right,valid);
        if(abs(lh-rh) > 1){
            valid =0;
        }
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
         bool valid = 1;
        hight(root ,valid);
        return valid;
    }
};