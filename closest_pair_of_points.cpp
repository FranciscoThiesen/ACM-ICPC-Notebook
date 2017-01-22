struct Point {
    int x, y, i;
    Point(int x = 0, int y = 0, int i = 0) : x(x), y(y), i(i) {}
    Point operator- (const Point &o) const { return Point(x - o.x, y - o.y); }
    int operator* (const Point &o) const { return x * o.x + y * o.y; }
    bool operator< (const Point &o) const {
        return y != o.y ? y < o.y : x < o.x;
    }
    void read() {
        scanf("%d %d", &x, &y);
    }
};

double abs(const Point &p) {
    return sqrt(p * p);
}

int main() {
    int n;
    Point pnts[MAXN];
    set<Point> box;
    set<Point>::iterator it;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        pnts[i].read();
        pnts[i].i = i;
    }
    sort(pnts, pnts+n, [] (const Point &p, const Point &q) {
        return p.x != q.x ? p.x < q.x : p.y < q.y;
    });
    double best = inf;
    int u, v;
    box.insert(pnts[0]);
    for (int i = 1, j = 0; i < n; i++) {
        while (j < i && pnts[i].x - pnts[j].x > best)
            box.erase(pnts[j++]);
        for (it = box.lower_bound(Point(pnts[i].x-best, pnts[i].y-best));
                it != box.end() && it->y <= pnts[i].y + best; it++) {
            double tmp = abs(pnts[i] - *it);
            if (tmp < best) {
                best = tmp;
                u = pnts[i].i, v = it->i;
            }
        }
        box.insert(pnts[i]);
    }
    if (u > v) swap(u,v);
    printf("%d %d %.6lf\n", u, v, best);
}
