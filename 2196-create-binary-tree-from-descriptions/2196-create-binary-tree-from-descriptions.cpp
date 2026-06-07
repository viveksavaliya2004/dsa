class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        vector<int> ans;
        map<int, TreeNode*> mp;
        set<int> child;

        for(int i = 0; i < descriptions.size(); i++) {

            if(mp.find(descriptions[i][0]) == mp.end()) {
                TreeNode *newnode = new TreeNode(descriptions[i][0]);
                mp[descriptions[i][0]] = newnode;
            }

            if(mp.find(descriptions[i][1]) == mp.end()) {
                TreeNode *newnode = new TreeNode(descriptions[i][1]);
                mp[descriptions[i][1]] = newnode;
            }

            if(descriptions[i][2] == 1) {
                mp[descriptions[i][0]]->left = mp[descriptions[i][1]];
            }
            else {
                mp[descriptions[i][0]]->right = mp[descriptions[i][1]];
            }

            child.insert(descriptions[i][1]);
        }

        for(int i = 0; i < descriptions.size(); i++) {
            if(child.find(descriptions[i][0]) == child.end()) {
                return mp[descriptions[i][0]];
            }
        }

        return NULL;
    }
};