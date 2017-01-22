int np, p[MAXN];
int lp[MAXN];

void sieve(int n) {
    for (int i = 2; i < n; i++)
        lp[i] = i;
    for (int i = 4; i < n; i += 2)
        lp[i] = 2;
    for (int i = 3; i*i < n; i += 2) if (lp[i] == i)
            for (int j = i*i; j < n; j += i) if (lp[j] == j)
                lp[j] = i;
    np = 0;
    p[np++] = 2;
    for (int i = 3; i < n; i += 2)
        if (lp[i] == i)
            p[np++] = i;
}
