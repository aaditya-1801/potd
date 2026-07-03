class Solution {
public:
    using ll = long long;
    const ll INF = 1e18;

    bool check(int mid, int n, vector<vector<pair<int, int>>>& adj,vector<bool>& online, long long k) {

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        vector<ll> dist(n, INF);

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d != dist[u])
                continue;

            for (auto& [v, w] : adj[u]) {

                if (w < mid)
                    continue;

                if (v != n - 1 && !online[v])
                    continue;

                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);

        int mx = 0;

        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            mx = max(mx, e[2]);
        }

        int l = 0, r = mx;
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (check(mid, n, adj, online, k)) {
                ans = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return ans;
    }
};
