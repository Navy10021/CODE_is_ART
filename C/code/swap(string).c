#include <stdio.h>
#include <string.h>

void swapChars(char* str, int idx1, int idx2){
    int length = strlen(str);

    if (idx1<0 || idx1>=length || idx2<0 || idx2>=length){
        printf("Invalid indices \n");
        return;
    }

    char temp = str[idx1];
    str[idx1] = str[idx2];
    str[idx2] = temp;
}

int main(){
    char input_str[] = "Yoonseop";
    printf("Original string : %s\n", input_str);

    int index1 = 0;
    int index2 = 4;

    swapChars(input_str, index1, index2);

    printf("After swaped string : %s\n", input_str);
    
    return 0;
}
