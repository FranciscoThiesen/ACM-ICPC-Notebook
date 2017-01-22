vi kmp(string& txt, string& ptt) {
    vi matches;

    // Calculo do vetor auxiliar lps (longest proper prefix
    // which is also suffix).
    vi lps(ptt.size() + 1, -1);

    for (int i = 1; i <= ptt.size(); i++) {
        int pos = lps[i - 1];
        while (pos != -1 and ptt[pos] != ptt[i - 1])
            pos = lps[pos];
        lps[i] = pos + 1;
    }    

    // String search.
    int sp = 0;
    int kp = 0;
    while(sp < txt.size()) {
        while (kp != -1 and (kp == ptt.size() || ptt[kp] != txt[sp]))
            kp = lps[kp];
        kp++; sp++;
        if (kp == ptt.size())
            matches.push_back(sp - ptt.size());
    }
    return matches;
}
