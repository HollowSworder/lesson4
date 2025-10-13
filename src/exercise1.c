#include <stdio.h>

int main(int argc, char** argv) {
    float num[10];
    float sum = 0;
    for(int i = 0; i < 10; i++) {
        scanf("%f", &num[i]);
        sum += num[i];
    }    
    float average = sum/10;
    printf("%.2f\n", average);
}