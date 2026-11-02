#include <stdio.h>
#include <stdlib.h>

int fib(int n){
    if (n == 0){
        return 0;
    }
    else if (n == 1){
        return 1;
    }
    else {
        return fib(n-1) + fib(n-2);
    }
}

int main(void) {
    printf("fib(0) = %d\n", fib(0));
    printf("fib(1) = %d\n", fib(1));
    printf("fib(4) = %d\n", fib(4));
    printf("fib(6) = %d\n", fib(6));

    return 0;
}