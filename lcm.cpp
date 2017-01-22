ll lcm(ll a, ll b) {
    if (a == 0 && b == 0) return 0;
    return a / __gcd(a,b) * b;
}