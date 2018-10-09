#include <stdio.h>

int in = 0;
int capacity;
int error_flag;
int pour_in(int volume);
int let_out(int volume);
int main(void) {
    int n, operation, volume, result;
      /*for operation, 1 means pour_in and 0 means let_out*/
    scanf("%d%d", &capacity, &n);
    while (n--) {
    	scanf("%d%d", &operation, &volume);
        result = operation ? pour_in(volume) : let_out(volume);
        printf("%d %d\n", result, error_flag);
        error_flag = 0;
    }
	return 0;
}
int pour_in(int volume) {
	in +=  volume;
	if (in > capacity) {
		error_flag = 1;
		in = capacity; 
	}
	return in;
}
int let_out(int volume) {
	in -= volume;
	if (in < 0) in = 0;
	return in;
}