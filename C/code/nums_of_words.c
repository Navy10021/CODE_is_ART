#include <stdio.h>
#include <stdbool.h>  // Required for bool data type

int main(){
    char str[10000];
    bool inWord = false; // flag to track if we're inside a word
    int wordCnt = 0;

    printf("Enter a string : ");
    scanf("%[^\n]", str);   // Read the entire line

    for (int i=0; str[i] != '\0'; i++){
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'){
            if (!inWord){
                inWord = true;
                wordCnt++;
            }
        }
        else {
            inWord = false;
        }
    }   

    printf("Number of words : %d \n", wordCnt);
    
    return 0;
}
