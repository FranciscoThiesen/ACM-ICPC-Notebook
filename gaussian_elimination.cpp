// Entrada: Matriz aumentada do sistema Ax=b, ou seja, com o vetor b a direita de A
// Saida: O numero de solucoes do sistema (0, 1, INF). Se o retorno for 1, as
// 	  solucoes podem ser verificadas em ans.

typedef vector<double> vd;
typedef vector<vd> vvd;

int gauss(vvd a, vd &ans, double EPS = 1e-9) {
    int n = sz(a);
    int m = sz(a[0]) - 1;
 
    vi where (m, -1);
    for (int col = 0, row = 0; col < m && row < n; col++) {
        int sel = row;
        for (int i = row; i < n; i++)
            if (abs(a[i][col]) > abs(a[sel][col]))
                sel = i;
        if (abs(a[sel][col]) < EPS)
            continue;
        for (int i = col; i <= m; i++)
            swap(a[sel][i], a[row][i]);
        where[col] = row;
 
        for (int i = 0; i < n; i++)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j = col; j <= m; j++)
                    a[i][j] -= a[row][j] * c;
            }
        row++;
    }
 
    ans.assign(m, 0);
    for (int i = 0; i < m; i++)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < m; j++)
            sum += ans[j] * a[i][j];
        if (abs(sum - a[i][m]) > EPS)
            return 0;
    }
 
    for (int i = 0; i < m; i++)
        if (where[i] == -1)
            return INF;
    return 1;
}
