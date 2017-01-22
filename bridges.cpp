int n, m;
vector<int> g[MAXN]; // lista de adjacencia, notacao horrorosa
int lbl[MAXN], low[MAXN], parent[MAXN], idx;
bool has_bridge;


void dfs(int u) {
    lbl[u] = low[u] = idx++;
    bool parent_found = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (lbl[v] == -1) {
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (low[v] == lbl[v]) {
                printf("%d -> %d\n", u, v);
                has_bridge = 1;
            }
        } else if (!parent_found && v == parent[u]) {
            parent_found = 1;
        } else {
            low[u] = min(low[u], lbl[v]);
        }
    }
}

void bridge() {
    for (int i = 1; i <= n; i++)
        lbl[i] = -1;
    for (int i = 1; i <= n; i++) {
        if (lbl[i] == -1) {
            idx = 0;
            parent[i] = i;
            dfs(i);
        }
    }
}