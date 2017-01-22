struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    Point operator+ (const Point &o) const { return Point(x + o.x, y + o.y); }
    Point operator- (const Point &o) const { return Point(x - o.x, y - o.y); }
    Point operator* (const double &o) const { return Point(x * o, y * o); }
    Point operator/ (const double &o) const { return Point(x / o, y / o); }
    double operator* (const Point &o) const { return x * o.x + y * o.y; }
    double operator% (const Point &o) const { return x * o.y - o.x * y; }
    bool operator== (const Point &o) const {
        return cmp_double(x, o.x) == 0 && cmp_double(y, o.y) == 0;
    }
    bool operator< (const Point &o) const {
        return x != o.x ? x < o.x : y < o.y;
    }
    void read() {
        scanf("%lf %lf", &x, &y);
    }
    void print() {
        printf("(%lf,%lf)\n", x, y);
    }
}; 
typedef Point Vector;
double abs(Point p) {
    return sqrt(p * p);
}
Vector norm(Vector v) {
    return v / abs(v);
}
double ccw(Point p, Point q, Point r) {
    return cmp_double((q - p) % (r - p));
}
// angulo pqr
inline double angle(Point p, Point q, Point r) {
    Point u = p - q, v = r - q;
    return atan2(u % v, u * v);
}
// retorna true se q esta no segmento [p,r]
bool between(Point p, Point q, Point r) {
    return ccw(p, q, r) == 0 && cmp_double((p - q) * (r - q)) <= 0;
}
struct Segment {
    Point p, q;
    Segment() {}
    Segment(Point p, Point q) : p(p), q(q) {}
};
bool in_segment(Point p, Segment s) {
    double t;
    Vector v = s.q - s.p;
    if (cmp_double(v.x, 0) != 0)
        t = (p.x - s.p.x) / v.x;
    else
        t = (p.y - s.p.y) / v.y;
    return cmp_double(t, 0) >= 0 && cmp_double(t, 1) <= 0 && s.p + v * t == p;
}
struct Line {
    Vector v;
    Point p;
    // implementar init() se quiser eq da reta na forma ax + by = c
    int a, b, c;
    void init() {
        a = -v.y;
        b = v.x;
        c = a * p.x + b * p.y;
        int d = abs(__gcd(a, __gcd(b, c)));
        if (d != 1)
            a /= d, b /= d, c /= d;
        if (a < 0)
            a = -a, b = -b, c = -c;
        else if (a == 0 && b < 0)
            b = -b, c = -c;
    }
    Line() {}
    Line(Point p, Point q) : v(q-p), p(p) {
        init();
    }
    Line(Segment s) : v(s.q-s.p), p(s.p) {
        init();
    }
    Point operator() (double t) const { return p + v * t; }
    Vector normal() {
        return Vector(-v.y, v.x);
    }
};
pair<double, double> line_intersection(Line a, Line b) {
    double den = a.v % b.v;
    if (den == 0)
        return make_pair(inf, inf);
    double t = -(b.v % (b.p - a.p)) / den;
    double s = -(a.v % (b.p - a.p)) / den;
    return make_pair(t, s);
}
Point segment_intersection(Segment a, Segment b) {
    Line la = Line(a), lb = Line(b);
    pair<double, double> pdd = line_intersection(la, lb);
    double t = pdd.first, s = pdd.second;
    if (t == inf) {
        if (in_segment(b.p, a))
            return b.p;
        if (in_segment(b.q, a))
            return b.q;
        if (in_segment(a.p, b))
            return a.p;
        if (in_segment(a.q, b))
            return a.q;
        return Point(inf, inf);
    }
    if (cmp_double(t, 0) < 0 || cmp_double(t, 1) > 0)
        return Point(inf, inf);
    if (cmp_double(s, 0) < 0 || cmp_double(s, 1) > 0)
        return Point(inf, inf);
    return la(t);
}

double distPointToLine(Point p, Line l) {
    Vector n = l.normal();
    return (l.p - p) * n / abs(n);
}

struct Circle {
    Point p;
    double r;
    Circle() {}
    Circle(Point p, double r) : p(p), r(r) {}
};

bool in_circle(const Circle &c, const Point &p) {
    return cmp_double(abs(c.p - p), c.r) <= 0;
}

Point circumcenter(Point p, Point q, Point r) {
    Point a = p - r, b = q - r, c = Point(a*(p+r)/2, b*(q+r)/2);
    return Point(c % Point(a.y, b.y), Point(a.x, b.x) % c)/(a % b);
}

Point incenter(Point p, Point q, Point r) {
    double a = abs(r - q), b = abs(r - p), c = abs(q - p);
    return (p * a + q * b + r * c) / (a + b + c);
}

// Poligono p[]
int n;
Point p[MAX];

// area de p
double poly_area() {
    double s = 0;
    for (int i = 0; i < n; i++)
        s += p[i] % p[(i+1) % n];
    return abs(s/2);
}

// O(n): retorna -1 se q esta na borda, 1 se esta no interior ou 0 no exterior.
int in_poly(Point q) {
    double a = 0;
    for (int i = 0; i < n; i++) {
        if (between(p[i], q, p[(i+1) % n])) return -1;
        a += angle(p[i], q, p[(i+1) % n]);
    }
    return cmp_double(a) != 0;
}

// O(log N): retorna 1 se q esta na borda ou no interior e 0 caso contrario.

int in_poly(Point q) {
    int l = 0, r = n;
    while (l+1 < r) {
        int m = (l+r)/2;
        if (ccw(p[m], p[0], q) == 0)
            return between(h[0], q, h[m]);
        if (ccw(p[m], p[0], q) < 0) l = m;
        else r = m;
    }
    return cmp_double(angle(p[0], q, p[l]) + angle(p[l], q, p[r]) + angle(p[r], q, p[0])) != 0;
}
