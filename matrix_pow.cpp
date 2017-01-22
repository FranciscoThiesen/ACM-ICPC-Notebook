vvd multMatrix(vvd& A, vvd& B) {
    int n = sz(A), m = sz(A[0]), p = sz(B[0]);
    vvd ans(n, vd(p, 0.0));
    for (int i = 0; i < n; i++)
        for (int k = 0; k < m; k++)
            for (int j = 0; j < p; j++)
                ans[i][j] += A[i][k]*B[k][j];
    return ans;
}
vvd expMat(vvd& A, int e) {
    if (e == 0) {
        int n = sz(A);
        vvd ans(n, vd(n, 0));
        for (int i = 0; i < n; i++)
            ans[i][i] = 1.0;
        return ans;
    }
    vvd x = expMat(A, e/2);
    x = multMatrix(x,x);
    if (e&1)
        x = multMatrix(x,A);
    return x;
}