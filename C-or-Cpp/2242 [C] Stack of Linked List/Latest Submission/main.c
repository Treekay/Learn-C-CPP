#include <stdio.h>
#include "stack.h"

int main() {
    Node *top = NULL;
    int t, n, pop_num;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        push(&top, n);
    }

    scanf("%d", &t);
    while (t--) {
        pop_num = pop(&top);
        printf("%d ", pop_num);
    }
    printf("\n");

    if (top)
        del(&top);

    return 0;
}

