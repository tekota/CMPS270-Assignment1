#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// This function takes a pointer to a pointer to a char
// Needs the length of the arrays to be passed in
char** merge(char** a, char** b, int n, int m) {
    char** c = (char**)malloc((n + m) * sizeof(char*));
    for (int i = 0; i < n; i++) {
        c[i] = (char*)malloc(strlen(a[i]) * sizeof(char));
        strcpy(c[i], a[i]);
    }
    for (int i = 0; i < m; i++) {
        c[i + n] = (char*)malloc(strlen(b[i]) * sizeof(char));
        strcpy(c[i + n], b[i]);
    }
    return c;
}

// Main Function
// if you want to test this, you can change the values of the arrays
// Should manually update the sizes of the arrays
// With the implemented test it should return: ab / ac / za / zb / zzzzc
int main(){
    char* a[] = {"ab", "ac"};
    char* b[] = {"za", "zb", "zzzzc"};
    char** c = merge(a, b, 2, 3);
    for (int i = 0; i < 5; i++) {
        printf("%s\n", c[i]);
    }
}