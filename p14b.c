#include<stdio.h>

int main(void) {

    unsigned long max_step_num = 0;
    unsigned long max_step_count = 0;
    
    for (unsigned long i = 1; i < 1000000; i++) {
        unsigned long step_count = 1;
        unsigned long ii = i;
        while(ii != 1) {
            ii = ((ii & 1) == 1) ? (3 * ii + 1): (ii >> 1);
            step_count++;
        }

        if (max_step_count < step_count) {
            max_step_count = step_count;
            max_step_num = i;
        }
    }
    
    printf("%ld %ld\n", max_step_num, max_step_count);

    return 0;
}
