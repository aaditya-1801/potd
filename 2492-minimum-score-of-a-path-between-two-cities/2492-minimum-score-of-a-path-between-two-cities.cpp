class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        queue<int> q;
        vector<int> vis(n + 1, 0);

        q.push(1);
        vis[1] = 1;

        int ans = INT_MAX;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto &[v, w] : adj[u]) {
                ans = min(ans, w);

                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        return ans;
    }
};

// class Solution {
// public:
//     int ans = INT_MAX;

//     void dfs(int node, vector<vector<pair<int,int>>>& adj, vector<int>& vis) {
//         vis[node] = 1;

//         for (auto &[next, wt] : adj[node]) {
//             ans = min(ans, wt);

//             if (!vis[next])
//                 dfs(next, adj, vis);
//         }
//     }

//     int minScore(int n, vector<vector<int>>& roads) {
//         vector<vector<pair<int,int>>> adj(n + 1);

//         for (auto &road : roads) {
//             int u = road[0];
//             int v = road[1];
//             int w = road[2];

//             adj[u].push_back({v, w});
//             adj[v].push_back({u, w});
//         }

//         vector<int> vis(n + 1, 0);

//         dfs(1, adj, vis);

//         return ans;
//     }
// };