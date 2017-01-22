//Entrada: Vetor v[] de moedas e quantidade C
//Saida: menor quantidade de moedas que forma quantia C

int coinchange(vi& v, int C) {
    vi dp(C+1, INF);
    dp[0] = 0;
    for (int i = 1; i <= C; i++)
        for (int j = 0; j < n; j++)
            if (v[j] <= i)
                dp[i] = min(dp[i], dp[i-v[j]] + 1);
    return dp[C];
}
