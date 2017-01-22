//Entrada: vetor v[] com atividades no formato
//Saida: soma maxima dos pesos de atividades nao sobrepostas
//Obs: v[] e 1-indexado

struct Event { 
    int b, e, w; 
    Event () {} 
    Event (int b, int e, int w) : b(b), e(e), w(w) {} 
    bool operator< (const Event& o) const { 
        return e != o.e ? e < o.e : b < o.b; 
    } 
};

int was(vector<Event>& v) {
    int n = sz(v)-1;
    sort(v.begin()+1, v.end());
    vi dp(n+1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int lo = 0, hi = i-1;
        while (lo < hi) {
            int mid = (lo + hi + 1)/2;
            if (v[mid].e > v[i].b)
                hi = mid - 1;
            else
                lo = mid;
        }
        dp[i] = max(dp[i-1], v[i].w + dp[lo]);
    }
    return dp[n];
}
