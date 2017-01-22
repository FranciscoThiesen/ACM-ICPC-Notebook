int nf, f[MAXN], e[MAXN];
void factor(int n) {
    nf = 0;
    for (int i = 0; n != 1 && p[i]*p[i] <= n; i++) {
        if (n % p[i] == 0) {
            f[nf] = p[i];
            e[nf] = 1;
            n /= p[i];
            while (n % p[i] == 0) {
                e[nf]++;
                n /= p[i];
            }
            nf++;
        }
    }
    if (n != 1) {
        f[nf] = n;
        e[nf] = 1;
        nf++;
    }
}