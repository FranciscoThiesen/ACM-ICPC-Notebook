/*  Responde quantos elementos no intervalo [l, r]
    Aparecem pelo menos duas vezes */

struct Query {
    int l, r, i;
} query[MAXQ];

int answer;
int cnt[MAXN], v[MAXN], ans[MAXQ];

void add(int idx) {
    cnt[v[idx]]++;
    if (cnt[v[idx]] == 2)
        answer += 2;
    else if (cnt[v[idx]] > 2)
        answer++;
}
void remove(int idx) {
    cnt[v[idx]]--;
    if (cnt[v[idx]] == 1)
        answer -= 2;
    else if (cnt[v[idx]] > 1)
        answer--;
}
int main() {
    sort(query, query+q, [] (Query a, Query b) {
        if (a.l/SQRTN != b.l/SQRTN)
            return a.l < b.l;
        return a.r < b.r;
    });

    for (int i = 0, curl = 0, curr = -1; i < q; i++) {
        while (curl > query[i].l)
            add(--curl);
        while (curr < query[i].r)
            add(++curr);
        while (curl < query[i].l)
            remove(curl++);
        while (curr > query[i].r)
            remove(curr--);
        ans[query[i].i] = answer;
    }
}