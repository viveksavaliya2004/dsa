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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root == NULL) return v;

        queue<TreeNode*> q;
        int count = 0;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();

            vector<int> level;

            while(n--) {
                TreeNode* nodea = q.front();
                q.pop();

                level.push_back(nodea->val);

                if(nodea->left) q.push(nodea->left);
                if(nodea->right) q.push(nodea->right);
            }

            if(count == 1) {
                reverse(level.begin(), level.end());
            }

            
                v.push_back(level);


            count = !count;
        }

        return v;
    }
};