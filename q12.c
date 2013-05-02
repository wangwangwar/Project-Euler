#include<stdio.h>

int num_of_divisor(unsigned long long number);

int main(void) {
    unsigned long long tri = 0;
    for (int i=1;; i++) {
        tri += i;
        int num = num_of_divisor(tri);
        printf("%d\n", num);
        if (num > 500) {
            printf("%d\n", tri);
            break;
        }
    }

    return 0;
}

int num_of_divisor(unsigned long long number) {
    int num = 0;
    for (int i = 2; i <= number/2; i++) {
        if (number % i == 0) {
            num++;
        }
    }
    return num + 2;
}
