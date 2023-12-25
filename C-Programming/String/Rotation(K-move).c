#include <stdio.h>
#include <string.h>

void rotateStr(char * str, int k){
    int len = strlen(str);
    k = k % len;

    char temp[len + 1];                 // Create a temporary buffer to store rotated string
    strncpy(temp, str + len - k, k);    // Copy the last k characters
    strncpy(temp + k, str, len - k);    // Copy the remaining characters
    temp[len] = '\0';
    strcpy(str, temp);                  // Copy the rotated string
}

int main(){
    char str[] = "ABCD";
    int rotations = strlen(str);

    for (int i = 0; i < rotations; i++){
        rotateStr(str, i);
        printf("%s\n", str);
    }
}
