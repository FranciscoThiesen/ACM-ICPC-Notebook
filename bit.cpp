struct BIT {
    int n;
    vi bit;
    BIT(int _n) : n(_n+1) {
        bit.resize(n+1, 0);
    }
    void update(int x, int val) {
        x++;
        for (; x <= n; x += x & -x)
            bit[x] += val;
    }
    int query(int x) {
        x++;
        int ret = 0;
        for (; x > 0; x -= x & -x)
            ret += bit[x];
        return ret;
    }
    int query(int l, int r) {
        return query(r)-query(l-1);
    }
};