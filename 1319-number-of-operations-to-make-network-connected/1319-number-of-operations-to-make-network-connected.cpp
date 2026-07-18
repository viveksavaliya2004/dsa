class DisjointSet {
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        // If there are fewer than n-1 cables, it's impossible.
        if (connections.size() < n - 1)
            return -1;

        DisjointSet ds(n);

        int extraEdges = 0;

        for (auto &it : connections) {
            int u = it[0];
            int v = it[1];

            if (ds.findPar(u) == ds.findPar(v)) {
                extraEdges++;
            }
            else {
                ds.unionByRank(u, v);
            }
        }

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (ds.findPar(i) == i)
                components++;
        }

        int requiredEdges = components - 1;

        if (extraEdges >= requiredEdges)
            return requiredEdges;

        return -1;
    }
};