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
    vector<double> averageOfLevels(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        vector<double> ans;

        while(!q.empty()){
            int sz = q.size();
            int ok = sz;
            double sum = 0 ;

            while(sz){

                TreeNode * curr = q.front();

                q.pop();

                if(curr->left != NULL){
                    q.push(curr->left);
                }

                if(curr->right != NULL){
                    q.push(curr->right);
                }

                
                sum += curr->val;

                sz--;
                

            }

            ans.push_back(sum/ok);
            sum = 0;

            
        }


        return ans;

        
    }
};