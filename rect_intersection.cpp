struct Rect {
    // Ponto superior esquerdo.
    int x1, y1;
    // Ponto inferior direito.
    int x2, y2;
    Rect() {
        x1 = y2 = -INF;
        y1 = x2 = INF;
    }
    Rect(int a, int b, int c, int d) : x1(a), y1(b), x2(c), y2(d) {}
    void read() {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    }
    void print() {
        printf("%d %d %d %d\n", x1, y1, x2, y2);
    }
    Rect intersection(Rect a) {
        Rect intersect = *this;
        if (a.x1 > intersect.x1) intersect.x1 = a.x1;
        if (a.y1 < intersect.y1) intersect.y1 = a.y1;
        if (a.x2 < intersect.x2) intersect.x2 = a.x2;
        if (a.y2 > intersect.y2) intersect.y2 = a.y2;
        return intersect;
    }
};