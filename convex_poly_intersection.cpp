// Utilizar implementacoes das funcoes abaixo, mesmo que ja definidas anteriormente

typedef vector<Point> Polygon;

inline int ccw(Point p, Point q, Point r) {
    return cmp_double((p - r) % (q - r));
}

bool between(Point p, Point q, Point r) {
    return ccw(p, q, r) == 0 && cmp_double((p - q) * (r - q)) <= 0;
}

// Do segments [p,q] and [r,s] have an intersection?
bool seg_intersect(Point p, Point q, Point r, Point s) {
    Point A = q - p, B = s - r, C = r - p, D = s - q;
    int a = cmp_double(A % C) + 2 * cmp_double(A % D);
    int b = cmp_double(B % C) + 2 * cmp_double(B % D);
    if (a == 3 || a == -3 || b == 3 || b == -3) return false;
    if (a || b || p == r || p == s || q == r || q == s) return true;
    int t = (p < r) + (p < s) + (q < r) + (q < s);
    return t != 0 && t != 4;
}

// Finds intersection between lines (p,q) and (r,s)
// (Warning: Divides by zero if parallel! Will return NaN or INF in this case)
Point line_intersect(Point p, Point q, Point r, Point s) {
    Point a = q - p, b = s - r, c = Point(p % q, r % s);
    return Point(Point(a.x, b.x) % c, Point(a.y, b.y) % c) / (a % b);
}

int in_poly(Point p, Polygon& T) {
    double a = 0; int N = T.size();
    for (int i = 0; i < N; i++) {
        if (between(T[i], p, T[(i+1) % N])) return -1;
        a += angle(T[i], p, T[(i+1) % N]);
    }
    return cmp_double(a) != 0;
}

Polygon poly_intersect(Polygon& P, Polygon& Q) {
    int m = Q.size(), n = P.size();
    if (m == 0 || n == 0) return Polygon();
    int a = 0, b = 0, aa = 0, ba = 0, inflag = 0;
    Polygon R;
    while ((aa < n || ba < m) && aa < 2*n && ba < 2*m) {
        Point p1 = P[a], p2 = P[(a+1) % n], q1 = Q[b], q2 = Q[(b+1) % m];
        Point A = p2 - p1, B = q2 - q1;
        int cross = cmp_double(A % B), ha = ccw(p2, q2, p1), hb = ccw(q2, p2, q1);
        if (cross == 0 && ccw(p1, q1, p2) == 0 && cmp_double(A * B) < 0) {
            if (between(p1, q1, p2)) R.push_back(q1);
            if (between(p1, q2, p2)) R.push_back(q2);
            if (between(q1, p1, q2)) R.push_back(p1);
            if (between(q1, p2, q2)) R.push_back(p2);
            if (R.size() < 2) return Polygon();
            inflag = 1; break;
        } else if (cross != 0 && seg_intersect(p1, p2, q1, q2)) {
            if (inflag == 0) aa = ba = 0;
            R.push_back(line_intersect(p1, p2, q1, q2));
            inflag = (hb > 0) ? 1 : -1;
        }
        if (cross == 0 && hb < 0 && ha < 0) return R;
        bool t = cross == 0 && hb == 0 && ha == 0;
        if (t ? (inflag == 1) : (cross >= 0) ? (ha <= 0) : (hb > 0)) {
            if (inflag == -1) R.push_back(q2);
            ba++; b++; b %= m;
        } else {
            if (inflag == 1) R.push_back(p2);
            aa++; a++; a %= n;
        }
    }
    if (inflag == 0) {
        if (in_poly(P[0], Q)) return P;
        if (in_poly(Q[0], P)) return Q;
    }
    unico(R);
    if (R.size() > 1 && R.front() == R.back()) R.pop_back();
    return R;
}

int main(int argc, char const *argv[]) {
    int n, m;
    scanf("%d %d", &n, &m);
    Polygon P(n), Q(m);
    for (int i = 0; i < n; i++)
        P[i].read();
    for (int i = 0; i < m; i++)
        Q[i].read();
    Polygon R = poly_intersect(P, Q);
    for (auto &x: R) x.print();
    return 0;
}
