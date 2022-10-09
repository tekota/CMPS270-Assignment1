#include <stdio.h>
#include <stdlib.h>


int hamming_distance(int x, int y) {
    int z = x ^ y;
    int count = 0;
    while (z) {
        count += z & 1;
        z >>= 1;
    }
    return count;
}

int main(){
    int x =1;
    int y=1;

    while (x>=0 && y>=0){
    printf("Enter two numbers (or a negative number to stop): ");
    scanf("%d %d", &x, &y);
    printf("\n");
    printf("Hamming distance: %d\n", hamming_distance(x, y));
    printf("\n");

    }
    
    return 0;
}