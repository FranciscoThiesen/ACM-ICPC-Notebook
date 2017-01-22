//Entrada: Vetor v[] de moedas e quantidade C
//Saida: quantidade de maneiras de formar quantia C

int coinchange(vi& v, int C) {
    vi dp(C+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= C; i++)
        for (int j = 0; j < n; j++)
            if (v[j] <= i)
                dp[i] += dp[i - v[j]];

    return dp[C];
}
