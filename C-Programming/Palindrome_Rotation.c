#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Rotation to make Palindrome.

int isPalindrome(char str[]) {
    int st = 0;
    int en = strlen(str) - 1;
    while (st < en) {
        if (str[st] != str[en])
            return 0;
        st++;
        en--;
    }
    return 1;
}

char * rotateStr(char str[], int n){
    int len = strlen(str);
    n = n % len;
    if (n < 0){
        n = len + n;
    }
    char * rotated = (char*)malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++){
        rotated[i] = str[(i+n) % len];
    }
    rotated[len] = '\0';
    return rotated;
}

int isRotatedPalindrome(char str[]){
    if (isPalindrome(str))
        return 1;
    int n = strlen(str);
    for (int i = 0; i < n; i++){
        if (isPalindrome(rotateStr(str, i))){
            printf("%s\n", rotateStr(str,i));
            return 1;
        }
    }
    return 0;
}

int main(void){
    char input[] = "AABB";
    if(isRotatedPalindrome(input)){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}