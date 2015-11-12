#include <stdio.h>

#define N 4

typedef struct {
    int val;
    int kval;
} cell;

cell min (cell a, int b, int k) {
    if (b < a.val) {
        cell ret;
        ret.val = b;
        ret.kval = k;
        return ret;
    }
    return a;
}

int main () {
    cell s[N][N];
    int d[N + 1] = {13,5,89,3,34};
    int i, j, k, a, b;

    for (i = 0; i < N; i++) {
        s[i][i].val = 0;
        s[i][i].kval = -1;
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N - i; j++) {
            a = j;
            b = j + i;
            for (k = 0; k < b; k++) {
                if (k == a) {
                    s[a][b].val = s[a][k].val + s[k + 1][b].val + d[a]*d[k+1]*d[b+1];
                    s[a][b].kval = k;
                } else if (k > a) {
                    s[a][b] = min(s[a][b],s[a][k].val + s[k + 1][b].val + d[a]*d[k+1]*d[b+1], k);
                }
            }
        }
    }

    for (i = -1; i < N; i++) {
        for (j = 1; j < N - i; j++) {
            a = j - 1;
            b = j + i;
            printf("%d\t", s[a][b].val);
        }
        printf("\n");
    }

    for (i = -1; i < N; i++) {
        for (j = 1; j < N - i; j++) {
            a = j - 1;
            b = j + i;
            printf("%d\t", s[a][b].kval + 1);
        }
        printf("\n");
    }

    return 0;
}