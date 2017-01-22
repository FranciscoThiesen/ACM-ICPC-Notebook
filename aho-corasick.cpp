struct Node {
    map<char, int> adj;
    int fail;
    ii match;
    int next;
    void init() {
        adj.clear();
        fail = -1;
        match = mp(-1, -1);
        next = -1;
    }
    int getChild(const char &c) {
        map<char, int>::iterator it = adj.find(c);
        if (it != adj.end())
            return it->nd;
        return -1;
    }
};

int qntNodes, qntPatts;
Node trie[MAX];
void init() {
    trie[0].init();
    qntNodes = 1;
    qntPatts = 0;
}
void addWord(const char *word) {
    int node = 0, aux = -1;
    for (int i = 0; word[i]; i++) {
        aux = trie[node].getChild(word[i]);
        if (aux == -1) {
            trie[qntNodes].init();
            aux = qntNodes++;
            trie[node].adj[word[i]] = aux;
        }
        node = aux;
    }
    trie[node].match = mp(qntPatts++, strlen(word));
}
void build() {
    queue<int> q;
    map<char, int>::iterator it;
    trie[0].fail = -1;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (it = trie[u].adj.begin(); it != trie[u].adj.end(); it++) {
            int v = it->nd;
            char c = it->st;
            q.push(v);
            int f = trie[u].fail;
            while (f >= 0 && trie[f].getChild(c) == -1)
                f = trie[f].fail;
            f = f >= 0 ? trie[f].getChild(c) : 0;
            trie[v].fail = f;
            trie[v].next = trie[f].match.st >= 0 ? f : trie[f].next;
        }
    }
}
void search(const char *text) {
    int node = 0;
    for (int i = 0; text[i]; i++) {
        while (node >= 0 && trie[node].getChild(text[i]) == -1)
            node = trie[node].fail;
        node = node >= 0 ? trie[node].getChild(text[i]) : 0;
        int aux = node;
        while (aux >= 0) {
            if (trie[aux].match.st >= 0) {
                // do something with the match
                printf("patt: %d, pos: %d\n",
                    trie[aux].match.st,
                    i - trie[aux].match.nd + 1);
            }
            aux = trie[aux].next;
        }
    }
}
