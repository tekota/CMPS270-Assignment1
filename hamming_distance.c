#include <stdio.h>
#include <stdlib.h>

// Function to calculate the hamming distance between two strings
// Takes 2 prositve strings as input 
int hamming_distance(int x, int y) {
    int z = x ^ y;
    int count = 0;
    while (z) {
        count += z & 1;
        z >>= 1;
    }
    return count;
}

// Main function
// Runs a loop as long as the user wants to continue

// 0 1 should give 1
// 0 3 should give 2
// 1 3 should give 1
int main(){
    int x =1;
    int y=1;

    while (x>=0 && y>=0){
    printf("Enter two numbers (or a negative number to stop): ");
    scanf("%d %d", &x, &y);
    printf("\n");
    if (y<0){
        printf("Needs to be a positive number, try again");
        break;
    }
    printf("Hamming distance: %d\n", hamming_distance(x, y));
    printf("\n");

    }
    
    return 0;
}