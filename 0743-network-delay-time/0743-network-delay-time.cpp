class Solution {
public:
    // Time: O((V + E) log V)
    // Space: O(V + E)

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto& edge : times) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;

        vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {

            auto [currDist, node] = pq.top();
            pq.pop();

            if (currDist > dist[node]) continue;

            for (auto& [next, wt] : adj[node]) {
                if (dist[next] > currDist + wt) {
                    dist[next] = currDist + wt;
                    pq.push({dist[next], next});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {

            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};