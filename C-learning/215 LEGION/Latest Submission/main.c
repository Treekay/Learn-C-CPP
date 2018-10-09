#include <stdio.h>

int main (void) {
	int n, m, k, i, x, y;
	int max = 0;
	scanf ("%d%d%d",&n,&m,&k);
	int sx, sy, tx, ty;
	int mountain[500][500] = {0};
	for (i = 0; i < k; i++) {
		scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
		for  (x = sx - 1; x <= tx - 1;x++) {
			for (y = sy - 1; y <= ty - 1;y++) {
				mountain[x][y]++;
			}
		}
	}
	for (x = 0; x < n; x++) {
		for (y = 0; y < m; y++) {
			if (mountain[x][y] > max) max = mountain[x][y];
		}
	}
	printf("%d\n",max);
	return 0;
}