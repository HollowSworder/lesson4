#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    double x = atof(argv[1]);
    int k = atoi(argv[2]);
    double array[10];
    
    for(int i = 0; i < 10; i++) {
        scanf("%lf", &array[i]);
    }
    
    for(int i = 9; i > k; i--) {
        array[i] = array[i-1];
    }
    array[k] = x;
    
    for(int i = 0; i < 10; i++) {
        printf("%g ", array[i]);
    }
    printf("\n");
    
    return 0;
}