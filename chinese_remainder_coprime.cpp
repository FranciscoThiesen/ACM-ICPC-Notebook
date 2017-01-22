struct teq { 
    int r, n; // x = r (mod n) 
}; 

int qnt; 
teq eqs[MAXN];

int chinese_remainder_algorithm() { 
    int beta, sum = 0, n = 1; 
    for (int i = 0; i < qnt; i++) 
        n *= eqs[i].n; 
    for (int i = 0; i < qnt; i++) { 
        beta = egcd(eqs[i].n, n/eqs[i].n).second; 
        while (beta < 0) 
            beta += eqs[i].n; 
        sum += (eqs[i].r * beta * n/eqs[i].n) % n; 
    } 
    return sum;
}