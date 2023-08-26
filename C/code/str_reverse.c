#include <stdio.h>
#include <string.h>

void reverseStr(char str[]){
    int length = strlen(str);

    for (int i=0; i < length/2; i++){
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void reverseRecursion(char str[], int i, int j){
    if (i >= j){
        return; // base case : if start is greater than end -> out
    }
    // Swap characters at start and end idx
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;

    reverseRecursion(str, i+1, j-1);
}

int main(){
    char input_str[] = "Lee yoon seop";
    int length = strlen(input_str);

    printf("Original : %s\n", input_str);

    reverseStr(input_str);
    printf("Reverse : %s\n", input_str);

    reverseRecursion(input_str, 0, length-1);
    printf("Reverse again : %s\n", input_str);

    return 0;
}
