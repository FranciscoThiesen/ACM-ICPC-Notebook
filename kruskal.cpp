// Vertices de 0 a n-1
int kruskal(viii &edges, int n) {
    sort(edges.begin(), edges.end());

    UnionFind ds(n);

    int cost = 0;
    for (int i = 0; i < sz(edges); i++)
        cost += edges[i].fi * ds.unions(edges[i].se.fi, edges[i].se.se);

    return cost;
}
