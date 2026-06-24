class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> color(n, -1);

        for (int start = 0; start < n; start++) {

            if (color[start] != -1)
                continue;

            queue<int> q;
            q.push(start);

            color[start] = 0;

            while (!q.empty()) {

                int node = q.front();
                q.pop();

                for (int nbr : graph[node]) {

                    if (color[nbr] == -1) {

                        color[nbr] = 1 - color[node];
                        q.push(nbr);
                    }

                    else if (color[nbr] == color[node]) {

                        return false;
                    }
                }
            }
        }

        return true;
    }
};