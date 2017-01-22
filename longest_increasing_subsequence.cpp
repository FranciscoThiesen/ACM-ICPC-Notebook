//Saida: ans[i] := indice do i-esimo elemento da maior subsequencia crescente

vi find_lis(vi& v) {
    int n = sz(v), len = 0;
    vi tam(n), dad(n);
    for (int i = 0; i < n; i++) {
        int lo = 0, hi = len;
        while (lo < hi) {
            int mid = (lo+hi) / 2;
            if (v[tam[mid]] < v[i])
                lo = mid+1;
            else
                hi = mid;
        }
        dad[i] = (lo > 0) ? tam[lo-1] : -1;
        tam[lo] = i;
        if (lo == len) len++;
    }
    vi ans(len);
    // se quiser a sequencia e nao apenas os indices, trocar u por v[u]
    for (int u = tam[len-1], i = len-1; u != -1; u = dad[u], i--)
        ans[i] = u;
    return ans;
}
