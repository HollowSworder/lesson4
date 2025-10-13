#include <stdio.h>
#include <math.h>

int main() {
    double array[10];
    double sum = 0;
    
    for(int i = 0; i < 10; i++) {
        scanf("%lf", &array[i]);
        sum += array[i];
    }
    double average = sum / 10;
    average = round(average * 100) / 100;
    printf("%.2lf\n", average); 
}
