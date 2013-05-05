#include<stdio.h>

int step(unsigned long n, unsigned long step_count);
    
int main(void) {
    unsigned long max_step_num = 0;
    unsigned long max_step_count = 0;
    for (unsigned long i = 1; i < 1000000; i++) {
        unsigned long step_count = step(i, 0);
        if (max_step_count < step_count) {
            max_step_count = step_count;
            max_step_num = i;
        }
    }
    printf("%ld %ld\n", max_step_num, max_step_count);
    return 0;
}

int step(unsigned long n, unsigned long step_count) {
    if (n == 1) {
        return step_count + 1;
    } else if (n % 2 == 0) {
        return step(n / 2, step_count + 1);
    } else {
        return step(n * 3 + 1, step_count + 1);
    }
}
