#include <stdio.h>
#include <stdlib.h>

// THIS PROGRAM IS BUILT ASSUMING THE ARRAY CONTAINTS ONLY 1s, 2s AND 3s
const int SIZE = 10;
int A[SIZE] = {1,2,3,1,1,2,3,1,2,1};

void printArray(int A[]){
    for(int i = 0; i < SIZE; i++){
        printf("%d\t%d ", i, A[i]);
        printf("\n");
    }
}

int max(int a, int b, int c){
    if(a > b && a > c){
        return a;
    }else if(b > a && b > c){
        return b;
    }else{
        return c;
    }
}

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

    // Value for 2
    printf("2\t%d\t", count2);
    for (int i = 0; i < count2; i++){
        printf("*");
    }
    
    // Value for 3
    printf("3\t%d\t", count3);
    for (int i = 0; i < count3; i++){
        printf("*");
    }

}



void swapValues(int A[], int a, int b){
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

void bubbleSort(int A[]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE - 1; j++){
            if(A[j] > A[j+1]){
                swapValues(A, j, j+1);
            }
        }
    }
}

int median(int A[]){
    bubbleSort(A);
    return A[SIZE/2];
}

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

int isSorted(int A[]){
    for(int i = 0; i < SIZE - 1; i++){
        if(A[i] > A[i+1]){
            return 0;
        }
    }
    return 1;
}

int main(){
    printArray(A);
    if (isSorted(A)){
        printf("The array is sorted");
    }else{
        printf("The array is not sorted");
    }
    bubbleSort(A);
    if (isSorted(A)){
        printf("The array is sorted");
        printArray(A);
    }
    arrayHistogram(A);
    printf("The median is %d", median(A));
    printf("The mode is %d", mode(A));
}