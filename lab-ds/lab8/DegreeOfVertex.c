#include <stdio.h>

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int deg[n];

    for (int i = 0; i < n; i++)
        deg[i] = 0; 

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        deg[u]++;
        deg[v]++;
    }

    printf("%d", deg[k]);

    return 0;
}