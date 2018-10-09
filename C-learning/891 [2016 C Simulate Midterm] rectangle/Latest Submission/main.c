#include <stdio.h>

int main() {
	int t, i, j, k, p, side1, side2;
	scanf("%d",&t);
	
	for (i = 0; i < t; ++ i) {
		int n;
		scanf("%d",&n);
		int array[2][n];
		
		for (j = 0; j < n; ++ j) {
			scanf("%d%d",&array[0][j],&array[1][j]);
		}
		
		for (j = 0; j < n; ++ j) {
			for (k = 0; k < n; ++ k) {
				if (k == j) continue; 
				if (array[0][k] == array[0][j]) {
					side1 = array[1][k] + array[1][j];
					side2 = array[0][j];
					for (p = 0; p < n; ++ p) {
						if (p == j || p == k) continue;
						if (array[0][p] == side1 || array[0][p] == side2 
						|| array[1][p] == side1 || array[1][p] == side2) {
							printf("Yes\n");
							goto Break;
						}
					} 
				}
				if (array[1][k] == array[0][j]) {
					side1 = array[0][k] + array[1][j];
					side2 = array[0][j];
					for (p = 0; p < n; ++ p) {
						if (p == j || p == k) continue;
						if (array[0][p] == side1 || array[0][p] == side2 
						|| array[1][p] == side1 || array[1][p] == side2) {
							printf("Yes\n");
							goto Break;
						}
					} 
				}
				if (array[0][k] == array[1][j]) {
					side1 = array[1][k] + array[0][j];
					side2 = array[1][j];
					for (p = 0; p < n; ++ p) {
						if (p == j || p == k) continue;
						if (array[0][p] == side1 || array[0][p] == side2 
						|| array[1][p] == side1 || array[1][p] == side2) {
							printf("Yes\n");
							goto Break;
						}
					}
				}
				if (array[1][k] == array[1][j]) {
					side1 = array[0][k] + array[0][j];
					side2 = array[1][j];
					for (p = 0; p < n; ++ p) {
						if (p == j || p == k) continue;
						if (array[0][p] == side1 || array[0][p] == side2 
						|| array[1][p] == side1 || array[1][p] == side2) {
							printf("Yes\n");
							goto Break;
						}
					} 
				}
			}
		}
		printf("No\n");
		Break: continue;
	}
}