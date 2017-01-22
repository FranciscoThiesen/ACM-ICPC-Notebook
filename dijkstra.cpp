/*  Entrada: Grafo g e vertice fonte s
    Saida:	Dijktra: vetor d[] com menor distancia de s ate todo v */

vi dijkstra(vvii& g, int s) {
    // comentar linha abaixo se ja tiver o tamanho n global
    int n = sz(g);
    set<ii> h;
    vi d(n, INF), vis(n, 0);
    d[s] = 0;
    vis[s] = 1;
    h.insert(mp(0, s));
    while (!h.empty()) {
        int u = h.begin()->se;
        h.erase(h.begin());
        vis[u] = 1;
        for (auto& x: g[u]) {
            int v = x.fi, w = x.se;
            if (!vis[v] and d[u] + w < d[v]) {
                h.erase(mp(d[v], v));
                d[v] = d[u] + w;
                h.insert(mp(d[v], v));
            }
        }
    }
    return d;
}
