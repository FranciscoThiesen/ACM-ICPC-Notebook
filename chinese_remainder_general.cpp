struct teq { 
    ll r, n; // x = r (mod n) 
}; 

ll inv(ll x, ll n) {
    ll ret = egcd(x, n).first;
    return mod(ret, n);
}

int qnt;
teq eqs[MAX];

pair<ll, ll> chines() {
    ll n = eqs[0].n, r = mod(eqs[0].r, n), auxr, d;
    for (int i = 1; i < qnt; i++) {
        d = __gcd(n, eqs[i].n);
        auxr = mod(eqs[i].r - r, eqs[i].n);
        if (auxr % d) return mp(-1, -1);
        r += auxr / d * n * inv(n/d, eqs[i].n/d);
        n *= eqs[i].n/d;
        r = mod(r, n);
    }
    return mp(r, n);
}