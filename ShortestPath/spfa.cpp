const int N = 1e5 + 5;
const int INF = 1e18;
vector<pii> edge[N];
vector<int> dis(N, INF);
bool spfa(int s, int n){
    vector<int> cnt(N, 0), vis(N, 0);
    queue<int> Q;
    dis[s] = 0; Q.push(s); vis[s] = 1;
    while (Q.size()) {
        int u = Q.front(); Q.pop();
        vis[u] = 0;
        for (auto [v, w] : edge[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n) {
                    return 1;
                }
                if (!vis[v]) Q.push(v), vis[v] = 1;
            }
        }
    }
    return 0;
}