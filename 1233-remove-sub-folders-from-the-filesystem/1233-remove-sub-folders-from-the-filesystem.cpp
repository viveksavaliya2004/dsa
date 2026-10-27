
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> ans;

        for (string path : folder) {
            if (ans.empty()) {
                ans.push_back(path);
            } 
            else {
                string prev = ans.back();

                // Check whether path is a sub-folder
                if (path.size() > prev.size() &&
                    path.substr(0, prev.size()) == prev &&
                    path[prev.size()] == '/') {
                    continue;
                }

                ans.push_back(path);
            }
        }

        return ans;
    }
};
