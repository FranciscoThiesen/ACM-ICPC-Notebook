typedef pair<ll, ll> pll;

pll egcd(ll a, ll b) {
    ll x = 0, lastx = 1, auxx;
    ll y = 1, lasty = 0, auxy;
    while (b) {
        ll q = a / b, r = a % b;
        a = b, b = r;
        auxx = x; 
        x = lastx - q*x, lastx = auxx; 
        auxy = y; 
        y = lasty - q*y, lasty = auxy; 
    } 
    return mp(lastx, lasty); 
}