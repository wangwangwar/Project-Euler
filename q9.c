#include<stdio.h>

int main(void) {
    for (long a=1; a<333; a++) {
        for (long b=a+1; b<1000; b++) {
            long c = 1000 - a - b;
            if (a*a + b*b == c*c) {
                printf("%d %d %d\n", a, b, c);
            }
        }
    }

    return 0;
}
