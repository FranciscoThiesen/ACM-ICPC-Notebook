//Saida: Z[i] := tamanho da maior string a partir do indice i que eh um prefixo de str

vi z_algo(string &str) {
    int n = sz(str);
    vi Z(n, 0);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            Z[i] = min (r - i + 1, Z[i - l]);
        while (i + Z[i] < n && str[Z[i]] == str[i + Z[i]])
            ++Z[i];
        if (Z[i] > r - i + 1)
            l = i, r = i + Z[i] - 1;
    }
    return Z;
}
