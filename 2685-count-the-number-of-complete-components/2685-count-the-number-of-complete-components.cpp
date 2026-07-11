class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;

    int nodes;
    int edges;

    void dfs(int u) {

        vis[u] = true;
        nodes++;

        edges += adj[u].size();

        for (int v : adj[u]) {
            if (!vis[v]) dfs(v);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edgesList) {

        adj.assign(n, {});
        vis.assign(n, false);

        for (auto &e : edgesList) {

            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {

            if (vis[i]) continue;

            nodes = 0;
            edges = 0;

            dfs(i);

            edges /= 2;

            if (edges == nodes * (nodes - 1) / 2) ans++;
        }

        return ans;
    }
};