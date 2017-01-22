typedef complex<long double> pt;
pt tmp[1<<20];

void fft(pt *in, int sz, bool inv) {
    if (sz == 1)
        return;
    for (int i = 0, j = 0, h = sz >> 1; i < sz; i += 2, j++) {
        in[j] = in[i];
        tmp[h+j] = in[i+1];
    }
    for (int i = sz >> 1; i < sz; i++)
        in[i] = tmp[i];
    sz >>= 1;
    pt *even = in, *odd = in + sz;
    fft(even, sz, inv);
    fft(odd, sz, inv);
    long double p = (inv ? -1 : 1) * M_PI / sz;
    pt w = pt(cosl(p), sinl(p)), w_i = 1;
    for (int i = 0; i < sz; i++) {
        pt conv = w_i * odd[i];
        odd[i] = even[i] - conv;
        even[i] += conv;
        w_i *= w;
    }
}