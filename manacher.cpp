char s[MAXN];
int p[2*MAXN]; // length of the palindrome centered at position (i-1)/2;

void manacher() {
    int m = 0;
    char t[2*MAXN];
    for (int i = 0; s[i]; i++) {
        t[m++] = '#';
        t[m++] = s[i];
        p[i] = 0;
    }
    t[m++] = '#';
    int c = 0, r = 0;
    for (int i = 0; i < m; i++) {
        int i_ = 2 * c - i;
        p[i] = r > i ? min(r-i, p[i_]) : i & 1;
        while (0 <= i-p[i]-1 && i+p[i]+1 < m && t[i-p[i]-1] == t[i+p[i]+1])
            p[i] += 2;
        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
    }
}
