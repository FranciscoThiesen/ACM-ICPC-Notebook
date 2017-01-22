// Vertices em g1 de 1 a n. Vertices em g2 de n+1 a n+m.
int n, m, e; 
vector<int> g1[MAXN]; 
int pair_g1[MAXN], pair_g2[MAXM], dist[MAXN]; 

bool bfs() { 
    queue<int> q; 
    for (int u = 1; u <= n; u++) { 
        dist[u] = INF; 
        if (pair_g1[u] == 0) { 
            dist[u] = 0; 
            q.push(u); 
        } 
    } 
    dist[0] = INF; 
    while (!q.empty()) { 
        int u = q.front(); q.pop(); 
        for (int i = 0; i < g1[u].size(); i++) { 
            int v = g1[u][i]; 
            if (dist[pair_g2[v]] == INF) { 
                dist[pair_g2[v]] = dist[u] + 1; 
                q.push(pair_g2[v]); 
            } 
        } 
    } 
    return dist[0] != INF; 
}
bool dfs(int u) { 
    if (u == 0) 
        return 1; 
    for (int i = 0; i < g1[u].size(); i++) { 
        int v = g1[u][i]; 
        if (dist[pair_g2[v]] == dist[u] + 1 && dfs(pair_g2[v])) { 
            pair_g1[u] = v; 
            pair_g2[v] = u; 
            return 1; 
        } 
    } 
    dist[u] = INF; 
    return 0;
} 
int hk() { 
    memset(pair_g1, 0, sizeof(pair_g1)); 
    memset(pair_g2, 0, sizeof(pair_g2)); 
    int matching = 0; 
    while (bfs()) 
        for (int u = 1; u <= n; u++) 
            if (pair_g1[u] == 0 && dfs(u)) 
                matching++; 
    return matching; 
}
int main() {
    scanf ("%d %d %d", &n, &m, &e);
    for (int i = 0, u, v; i < e; ++i) {
        scanf("%d %d", &u, &v);
        g1[u].push_back(n+v);
    }
    printf("%d\n", hk());
    return 0;
}
