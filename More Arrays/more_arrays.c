#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 char** concatinate(char* A[][], int n){
    char** B = malloc(n * sizeof(char*));
    for(int i = 0; i < n; i++){
        B[i] = malloc(100 * sizeof(char));
        strcpy(B[i], A[i]);
    }
    return B;
 }