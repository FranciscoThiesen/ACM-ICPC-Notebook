//Entrada: Vetores v[] e p[] com valores e pesos dos itens e capacidade C da mochila
//Saida: Valor maximo obtido

int knapsack(vi& v, vi& p, int C) {
    vi dp(C+1, 0);
    for (int i = 0; i < sz(v); i++)
        for (int j = C; j >= 1; j--)
            if (p[i] <= j)
                dp[j] = max(dp[j], v[i] + dp[j-p[i]]);
    return dp[C];
}
