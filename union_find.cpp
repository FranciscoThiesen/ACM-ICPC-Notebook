struct UnionFind {
    int nsize;
    vi parent, size;

    UnionFind(int n) : nsize(n) {
        size.resize(n, 1);
        parent.resize(n);
        iota(all(parent), 0);
    }

    int unions(int u, int v) {
        if (finds(u) == finds(v))
            return 0;
        size[parent[v]] += size[parent[u]];
        parent[parent[u]] = parent[v];
        nsize--;
        return 1;
    }

    int finds(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = finds(parent[u]);
    }
};