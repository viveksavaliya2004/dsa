class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;

    void dfs(string word, string beginWord, vector<string>& path) {

        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (auto &par : parent[word]) {
            path.push_back(par);
            dfs(par, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord,
                                       string endWord,
                                       vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        if (st.find(endWord) == st.end())
            return {};

        unordered_map<string, int> level;

        queue<string> q;
        q.push(beginWord);

        level[beginWord] = 0;

        while (!q.empty()) {

            string word = q.front();
            q.pop();

            int currLevel = level[word];

            string originalWord = word;

            for (int i = 0; i < word.size(); i++) {

                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    word[i] = ch;

                    if (st.find(word) != st.end()) {

                        // first time visited
                        if (!level.count(word)) {

                            level[word] = currLevel + 1;
                            q.push(word);

                            parent[word].push_back(originalWord);
                        }

                        // same shortest level
                        else if (level[word] == currLevel + 1) {

                            parent[word].push_back(originalWord);
                        }
                    }
                }

                word[i] = original;
            }
        }

        if (!level.count(endWord))
            return {};

        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, path);

        return ans;
    }
};