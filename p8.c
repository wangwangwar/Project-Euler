#include<stdio.h>
#include<stdlib.h>

long ctoi(char *c) {
    return (*c - '0');
}

long productof(char *p, int n) {
    long product = 1;
    for (int i=0; i<n; i++) {
        product *= ctoi(p);
        p--;
    }
    return product;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Must have a arg");
        exit(0);
    }
    
    char *p = argv[1];
    long product = 1;
    long max;
    int max_idx;
    for (int i=0; i<5; i++) {
        product *= ctoi(p++);
    }
    max = product;
    for (int i=5; *p; i++) {
        product = productof(p, 5);
        if (product > max) {
            max_idx = i;
            max = product;
        }
        printf("%d\n", product);
        p++;
    }
    
    printf("Max: %d, Idx: %d\n", max, max_idx);
    return 0;
}


