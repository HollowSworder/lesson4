#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int k = atoi(argv[1]);
    float num[10];
    for(int i=0; i<10; i++) {
        scanf("%f", &num[i]);
    }
    k = k%10;
    if (k<0) {
        k+=10;
    }
    for(int i = 0; i<10; i++){
        int index = (10 - k +i) %10;
        printf("%.3f\n", num[index]);        
    }
}
