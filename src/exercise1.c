#include <stdio.h>

int main() {
    double array[10];
    double sum = 0;
    
    for(int i = 0; i < 10; i++) {
        scanf("%lf", &array[i]);
        sum += array[i];
    }
    double average = sum / 10;
    average = (double)((int)(average * 100 + 0.5)) / 100;
    printf("%.2f\n", average);
    
    return 0;
}
