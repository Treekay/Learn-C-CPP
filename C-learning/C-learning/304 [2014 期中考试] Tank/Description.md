# [2014 期中考试] Tank

## Description:

There is a big tank(水槽) in the town and you are in charge of it. Please implement two functions int pour_in(int volume) and int let_out(int volume). These two function should return the remaining quantity of water in the tank. The capacity of the tank will be given in main.c, you should declare an int-variable error_flag which was initially set to 0 for main.c. The initial quantity of water in the tank is 0. Each time one of the function is called you should reset the error_flag to 0(so that main.c can know if the call causes error), and you should set the error_flag to 1 when and only when pour_in causes the tank to overflow(more than its capacity). If the tank doesn't have enough water to let out, just let out all the remaining water.

```c
    // main.c

    #include <stdio.h>
     
    int capacity;
    extern int error_flag;
     
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
      }
      return 0;
    }
```

## Hint:
Your job is to write two functions.

