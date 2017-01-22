// Saida: menor custo para comecar no vertice 0, fazer um tour pelos vertices 1...n-1 e retornar ao vertice 0.

int n;
ii p[MAX];
double pd[(1<<MAX)][MAX];

double cost(int i, int j) {
    return sqrt(pow2(p[i].st-p[j].st)+pow2(p[i].nd-p[j].nd));
}

double tsp() {
    for (int i = 0; i < (1<<n); i++)
        for (int j = 0; j < n; j++)
            pd[i][j] = inf;
    pd[0][0] = 0.0;

    for (int i = 1; i < (1<<n); i += 2) {
        for (int j = 0; j < n; j++) {
            if (i & (1<<j)) continue;
            for (int k = 0; k < n; k++)
                if (k != j and (i & (1<<k)))
                    pd[i][j] = min(pd[i][j], pd[i^(1<<k)][k] + cost(k,j));
        }
    }

    double ans = inf;
    for (int k = 0; k < n; k++)
        ans = min(ans, pd[((1<<n)-1)-(1<<k)][k] + cost(k,0));

    return ans;
}
