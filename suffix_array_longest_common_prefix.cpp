// Usar a partir da funcao initSA(string& _str)
// sa : array de sufixos
// pos:	inverso do array de sufixos, ie, pos[i] := o indice do sufixo i em sa[]
//	suf[i] < suf[j] se e somente se pos[i] < pos[j]

int n;
string str;
int sa[MAX], pos[MAX], cnt[MAX], nxt[MAX], bh[MAX], b2h[MAX], lcp[MAX];

void suffix_array() {
    for (int i = 0; i < n; i++)
        sa[i] = i;
    sort(sa, sa + n, [] (int a, int b) {
        return str[a] < str[b];
    });
    for (int i = 0; i < n; i++) {
        bh[i] = (i == 0 || str[sa[i]] != str[sa[i-1]]);
        b2h[i] = 0;
    }
    for (int h = 1; h < n; h <<= 1) {
        int buckets = 0;
        for (int i = 0, j; i < n; i = j) {
            j = i + 1;
            while (j < n && !bh[j])
                j++;
            nxt[i] = j;
            buckets++;
        }
        if (buckets == n)
            break;
        for (int i = 0; i < n; i = nxt[i]) {
            cnt[i] = 0;
            for (int j = i; j < nxt[i]; j++)
                pos[sa[j]] = i;
        }
        cnt[pos[n-h]]++;
        b2h[pos[n-h]] = 1;
        for (int i = 0; i < n; i = nxt[i]) {
            for (int j = i; j < nxt[i]; j++) {
                int s = sa[j] - h;
                if (s >= 0) {
                    int head = pos[s];
                    pos[s] = head + cnt[head]++;
                    b2h[pos[s]] = 1;
                }
            }
            for (int j = i; j < nxt[i]; j++) {
                int s = sa[j] - h;
                if (s >= 0 && b2h[pos[s]]) {
                    for (int k = pos[s] + 1; !bh[k] && b2h[k]; k++)
                        b2h[k] = 0;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            sa[pos[i]] = i;
            bh[i] |= b2h[i];
        }
    }
    for (int i = 0; i < n; i++)
        pos[sa[i]] = i;
}
void getlcp() {
    lcp[0] = 0;
    for (int i = 0, h = 0; i < n; i++) {
        if (pos[i] > 0) {
            int j = sa[pos[i] - 1];
            while (i + h < n && j + h < n && str[i+h] == str[j+h])
                h++;
            lcp[pos[i]] = h;
            if (h > 0)
                h--;
        }
    }
}
void initSA(string& _str) {
    str = _str;
    n = sz(str);
    suffix_array();
    getlcp();
}
