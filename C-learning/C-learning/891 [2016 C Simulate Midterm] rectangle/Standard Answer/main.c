#include<stdio.h>
int a[110][2][2];
int main() {
    int T, n;
    int i, j, k, x, y, z;
    int flag;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (i = 1; i <= n; i++) {
            scanf("%d%d", &a[i][0][0], &a[i][0][1]);
            a[i][1][0] = a[i][0][1];
            a[i][1][1] = a[i][0][0];
        }
        flag = 0;
        for (i = 1; i <= n; i++) {
            for (x = 0; x <= 1; x++)
            for (j = 1; j <= n; j++) {
                if (i == j) continue;
                for (y = 0; y <= 1; y++)
                for (k = 1; k <= n; k++) {
                    if (i == k || j == k) continue;
                    for (z = 0; z <= 1; z++) {
                        if (a[i][x][0] + a[j][y][0] == a[k][z][0]
                        && a[i][x][1] == a[j][y][1]) flag = 1;
                        if (a[i][x][0] == a[j][y][0]
                        && a[i][x][0] == a[k][z][0]) flag = 1;
                    }
                }
            }
        }
        if (flag) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}
