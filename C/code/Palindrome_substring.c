#include <stdio.h>
#include <string.h>

int palindrome(char str[], int l, int r) {
    
    while (l < r) {  // Corrected condition here
        if (str[l] != str[r]) {
            return 0;
        }
        l++;
        r--;
    }
    return 1;
}

void printPalinSubstring(char str[]){
    int length = strlen(str);

    for (int len=1; len<=length; len++){
        for (int start = 0; start <= length-len; start++){
            int end = start + len - 1;
            if(palindrome(str, start, end)){
                for (int i = start; i <= end; i++){
                    printf("%c", str[i]);
                    }
                    printf("\n");
                }
            }
        }
}

int main() {
    char input_str[] = "ABCBAA";

    printPalinSubstring(input_str);
    return 0;
}
