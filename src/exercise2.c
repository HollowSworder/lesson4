#include <stdio.h>

int main(int argc, char** argv) {
    float num[10];
    for(int i=9; i>=0; i--) {
        scanf("%f\n", &num[i]);
    }
    for(int i=0; i<10; i++) {
        printf("%.3f ", num[i]);
    }
}
