#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (void) {
	int num;
	scanf ("%d",&num);
	int i, t;
	char name[100][100] = {0};
	for (i = 0; i < num; i++) {
		scanf ("%s",name[i]);
		for (t = 0; t < strlen(name[i]); t++) {
			if (t == 0) {
				if ((!isalpha(name[i][t]))&&(name[i][t] != '_')) {
					printf("No\n");
					break;
				}
			}
			if ((!isalpha(name[i][t]))&&(!isdigit(name[i][t]))&&(name[i][t] != '_')) {
			  	printf ("No\n");
			  	break;
			}	
		}
		if ((t == strlen(name[i]))&&((isalpha(name[i][t-1]))||(isdigit(name[i][t-1]))||(name[i][t-1] == '_'))) printf("Yes\n");
	}
	return 0;
}