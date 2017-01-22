string lcs(string a, string b) {

    int n = a.length();
    int m = b.length();

    int maximum = 0;
    int ii = 0;
    int jj = 0;

    vvi dp(n+1, vi(m+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;

                if (dp[i][j] > maximum) {
                    maximum = dp[i][j];
                    ii = i; jj = j;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    string answer = "";


    while (ii and dp[ii][jj]) {
        answer.push_back(a[--ii]);
        jj--;
    }

    reverse(answer.begin(), answer.end());
    return answer;
}