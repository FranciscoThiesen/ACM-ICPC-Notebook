int n, m;
vector<int> g[MAX];
int lbl[MAX], low[MAX], idx, cnt_scc;
stack<int> st;
bool inSt[MAX];

void dfs(int u) {
    lbl[u] = low[u] = idx++;
    st.push(u);
    inSt[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (lbl[v] == -1) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (inSt[v]) {
            low[u] = min(low[u], lbl[v]);
        }
    }
    if (low[u] == lbl[u]) {
        printf("%d -> ", ++cnt_scc);
        int v;
        do {
            v = st.top();
            st.pop();
            inSt[v] = 0;
            printf("%d; ", v);
        } while (v != u);
        putchar('\n');
    }
}
void tarjan() {
    for (int i = 1; i <= n; i++) {
        lbl[i] = -1;
        inSt[i] = 0;
    }
    idx = cnt_scc = 0;
    for (int i = 1; i <= n; i++)
        if (lbl[i] == -1)
            dfs(i);
}