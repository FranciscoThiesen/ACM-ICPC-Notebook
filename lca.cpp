int n, m, u, v, w;
int anc[MAXN][LOGMAXN], dad[MAXN], lvl[MAXN], dist[MAXN];
vii g[MAXN];

void dfs(int u) {
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i].st, w = g[u][i].nd;
        if (v != dad[u]) {
            dad[v] = u;
            lvl[v] = lvl[u] + 1;
            dist[v] = dist[u] + w;
            dfs(v);
        }
    }
}


void pre() {
    dad[0] = lvl[0] = dist[0] = 0;
    dfs(0);
    for (int i = 0; i < n; i++)
        anc[i][0] = dad[i];
    for (int j = 1; 1<<j < n; j++)
        for (int i = 0; i < n; i++)
            anc[i][j] = anc[anc[i][j-1]][j-1];
}

int lca(int u, int v) {
    if (lvl[u] < lvl[v])
        swap(u, v);
    int log;
    for (log = 1; (1<<log) <= lvl[u]; log++);
    log--;
    for (int i = log; i >= 0; i--)
        if (lvl[u] - lvl[v] >= (1<<i))
            u = anc[u][i];
    if (u == v)
        return u;
    for (int i = log; i >= 0; i--)
        if (anc[u][i] != anc[v][i])
            u = anc[u][i], v = anc[v][i];
    return dad[u];
}
