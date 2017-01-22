#define B 33

llu powB[MAX];
void init() {
    powB[0] = 1;
    for (int i = 1; i < MAX; i++)
        powB[i] = B*powB[i-1];
}

void calc_hash(char *str, llu *h) {
    h[0] = 0;
    for (int i = 0; str[i]; i++)
        h[i+1] = B*h[i] + str[i];
}

llu get_hash(llu *h, int l, int r) {
    return h[r] - h[l]*powB[r-l];
}