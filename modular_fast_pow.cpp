ll power(ll b, ll e, ll mod = numeric_limits<ll>::max()) {
    if (e == 0) return 1;
    b %= mod;
    ll a = power(b, e/2, mod);
    a = (a*a) % mod;
    if (e&1) return (a*b) % mod;
    return a;
}

ll power(ll b, ll e, ll mod = numeric_limits<ll>::max()) {
    ll ret = 1;
    b = b % mod;
    while (e > 0) {
        if (e & 1) ret = (ret * b) % mod;
        e >>= 1;
        b = (b * b) % mod;
    }
    return ret;
}