#include <stdio.h>
#include <stdlib.h>

// THIS PROGRAM IS BUILT ASSUMING THE ARRAY CONTAINTS ONLY 1s, 2s AND 3s
const int SIZE = 10;
int A[SIZE] = {1,2,3,1,1,2,3,1,2,1};

// Function to print the array elements on each line
void printArray(int A[]){
    for(int i = 0; i < SIZE; i++){
        printf("%d\t%d ", i, A[i]);
        printf("\n");
    }
}

// Function to find the max 
int max(int a, int b, int c){
    if(a > b && a > c){
        return a;
    }else if(b > a && b > c){
        return b;
    }else{
        return c;
    }
}

// Function to count a particular element in an array
// int x needs to be in array
// Assuming the array contains only 1,2 and 3
int counter(int A[], int x){
    int count = 0;
    for(int i = 0; i < SIZE; i++){
        if(A[i] == x){
            count++;
        }
    }
    return count;
}

// Prints array histogram with '*'s 
void arrayHistogram(int A[]){
    printf("Value Frequency Histogram\n");
    int count1 = counter(A, 1);
    int count2 = counter(A, 2);
    int count3 = counter(A, 3);

    // Value for 1
    printf("1\t%d\t", count1);
    for (int i = 0; i < count1; i++){
        printf("*");
    }
    printf("\n");
    // Value for 2
    printf("2\t%d\t", count2);
    for (int i = 0; i < count2; i++){
        printf("*");
    }
    printf("\n");
    // Value for 3
    printf("3\t%d\t", count3);
    for (int i = 0; i < count3; i++){
        printf("*");
    }
    printf("\n");
}


// Swaps values of two indices in an array
void swapValues(int A[], int a, int b){
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

// Sorts the array in ascending order using swapValues
void bubbleSort(int A[]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE - 1; j++){
            if(A[j] > A[j+1]){
                swapValues(A, j, j+1);
            }
        }
    }
}

// Finds the median of the array
int median(int A[]){
    bubbleSort(A);
    return A[SIZE/2];
}

// Finds the mode of the array
int mode(int A[]){
    int count1 = counter(A, 1);
    int count2 = counter(A, 2);
    int count3 = counter(A, 3);

    int count = max(count1, count2, count3);
    if(count == count1){
        return 1;
    }else if(count == count2){
        return 2;
    }else{
        return 3;
    }
}

// Returns 0 if array is unsorted, and 1 otherwise
int isSorted(int A[]){
    for(int i = 0; i < SIZE - 1; i++){
        if(A[i] > A[i+1]){
            return 0;
        }
    }
    return 1;
}


// Tests every function in the program
// Uses the given array from the problem
// Median = 2
// Mode = 1
int main(){
    printArray(A);
    if (isSorted(A)){
        printf("The array is sorted\n");
    }else{
        printf("The array is not sorted\n");
    }
    bubbleSort(A);
    if (isSorted(A)){
        printArray(A);
        printf("The array is sorted\n");
    }
    arrayHistogram(A);
    printf("The median is %d\n", median(A));
    printf("The mode is %d\n", mode(A));
}