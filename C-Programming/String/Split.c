#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// return array[str1, str2, str3 ...]
char** split(const char * str, const char * delimiter, int * count){
    char * copy = strdup(str); // to avoid modifying Original str
    char * token = strtok(copy, delimiter);
    
    // Count the number of tokens
    int numTokens = 0;
    while (token != NULL){
        token = strtok(NULL, delimiter);
        numTokens++;
    }
    // Allocate memory
    char ** res = (char**)malloc(numTokens * sizeof(char*));
    
    // get token again
    strcpy(copy, str);  // Reset copy string
    token = strtok(copy, delimiter);
    // Store 
    for (int i = 0; i < numTokens; i++){
        res[i] = strdup(token);
        token = strtok(NULL, delimiter);
    }
    * count = numTokens;
    free(copy);
    
    return res;
}

void freeRes(char ** res, int count){
    for (int i = 0; i < count; i++){
        free(res[i]);
    }
    free(res);
}

int main(){
    const char * inputStr = "AB CD EF";
    const char * delimiter = " ";
    int numTokens;
    
    char ** tokens = split(inputStr, delimiter, &numTokens);
    printf("Tokens \n");
    for (int i = 0; i < numTokens; i++){
        printf("%s\n", tokens[i]);
    }
    printf("\n");
    freeRes(tokens, numTokens);
    return 0;
