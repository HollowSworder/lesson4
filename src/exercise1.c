#include <stdio.h>

int main() {
    float array[10];
    float sum = 0;
    
    for(int i = 0; i < 10; i++) {
        scanf("%f", &array[i]);
        sum += array[i];
    }
    
    printf("%.2f\n", sum / 10);
    return 0;
}
