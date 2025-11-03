#include <stdio.h>

int main() {
    float A[10][3];
    float B[3][10];
    float C[10][10];  
   
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%f", &A[i][j]);
        }
    }
   
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%f", &B[i][j]);
        }
    }
    for (int i = 0; i < 10; i++) {      
        for (int j = 0; j < 10; j++) {    
          
            for (int k = 0; k < 3; k++) {  
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%.3f ", C[i][j]);
        }
    }
    printf("\n");

    return 0;
}
