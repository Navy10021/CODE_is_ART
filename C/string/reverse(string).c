#include <stdio.h>
#include <string.h>

void reverse(char str[]) {    // string 은 배열이다. char str[] == char* str
    int length = strlen(str);
    int start = 0;
    int end = length - 1;
    char temp;

    while (start < end) {
        // Swap characters at start and end positions
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        // Move the start and end pointers towards each other
        start++;
        end--;
    }
}

int main() {
    //char str[100]; // Assuming a maximum string length of 100 characters
    //printf("Enter a string: ");
    //scanf("%s", str);
    char str[100] = "LEE YOON SEOP";
    // Reverse the string
    reverse(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
