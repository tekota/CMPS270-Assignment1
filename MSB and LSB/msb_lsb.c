#include <stdio.h>
#include <stdlib.h>


// Function that computes the position of the msb
// Takes a positive integer as input
int msb(int x) {
    int count = 0;
    while (x) {
        count += 1;
        x >>= 1;
    }
    return count-1;
}

// Function that computes the position of the lsb
// Takes a positive integer as input
int lsb(int x) {
    int count = 0;
    while (x) {
        if (x & 1) {
            return count;
        }
        count += 1;
        x >>= 1;
    }
    return -1;
}

// Main function
// Runs a loop as long as the user wants to continue
// 1 should give 0
// 9 should give 3
// Any power of 2 should give 0
int main(){
    int x;
    printf("Enter a positive non-zero number: ");
    scanf("%d", &x);
    // printf("\n");
    while(x<=0){
        printf("Needs to be a positive number, try again: ");
        scanf("%d", &x);
        printf("\n");
    }
    int output = abs(msb(x)-lsb(x));
    printf("Output: %d", output);
}