#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function takes a 2D array of strings and  concatinates the sub-strings into one within an array 
char** concat(char *a[][3], int s){
    int column = sizeof(a[0])/ sizeof(a[0][0]);
    char **b = (char**)malloc(s * sizeof(char*));

    for (int i = 0; i < s; i++){
        char temp[100] = "";
        b[i] = (char*)malloc(sizeof(char));
        for (int j = 0; j < column; j++){
            strcat(temp, a[i][j]);
            strcat(temp, " ");
        }
        strcpy(b[i], temp);
    }
    return b;
}

// Main function
// Should return "{"I LOVE CODING", "THIS IS SPARTA"}
int main(){
    char *a[][3] = {{"I", "LOVE", "CODING"}, {"THIS","IS", "SPARTA"}};
    int s = sizeof(a)/ sizeof(a[0]);
    char **b = concat(a, s);
    printf("{");
    for (int i = 0; i < s; i++){
        printf("%s", b[i]);
    }
    printf("}");
}