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
    int x,y=1;

    while (x>=0 && y>=0){

    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    printf("%d %d", x, y);
    printf("Hamming distance: %d", hamming_distance(x, y));

    }

    return 0;
}