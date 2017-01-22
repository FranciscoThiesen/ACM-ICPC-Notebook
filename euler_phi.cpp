//Cuidado com integer overflow
int phi(int n) {
    int ret = 1;
    for (int i = 0; n != 1 && p[i]*p[i] <= n; i++) {
        if (n % p[i] == 0) {
            int pk = p[i];
            n /= p[i];
            while (n % p[i] == 0) {
                pk *= p[i];
                n /= p[i];
            }
            ret *= pk - pk/p[i];
        }
    }
    if (n != 1)
        ret *= n-1;
    return ret;
}