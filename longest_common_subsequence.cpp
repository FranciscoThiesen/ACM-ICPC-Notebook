//Entrada: strings a e b
//Saida: string com a maior subsequencia em comum entre a e b

string lcs(string a, string b) {

    int n = a.length();
    int m = b.length();

    vvi dp(n+1, vi(m+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    string answer = "";

    int i = n;
    int j = m;

    while (i and j) {
        if (dp[i][j] == dp[i-1][j]) i--;
        else if (dp[i][j] == dp[i][j-1]) j--;
        else if (dp[i][j] == dp[i-1][j-1] + 1) answer.push_back(a[i-1]), i--, j--;
    }

    reverse(answer.begin(), answer.end());
    return answer;
}
