#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1. Substring을 Array(**substrings)에 저장하는 함수
void getAllSubstrings(char * str, char **substrings, int len){
    int count = 0;
    
    for (int i = 0; i < len; i++){
        for (int j = i; j < len; j++){
            for (int k = i; k <= j; k++){
                //printf("%c", str[k]);
            }
            //printf("\n");
            
            // Store the substring in the array
            int substringLen = j-i+1;
            substrings[count] = malloc((substringLen+1)*sizeof(char));
            strncpy(substrings[count], str + i, substringLen);
            substrings[count][substringLen] = '\0';
            count++;
        }
    }
}

// 2. Substring을 단순히 출력하는 함수
void printSubstr(char * str, int len){
	for (int i = 0; i < len; i++){ // start index
		for (int j = i; j < len; j++){	// end index
			for (int k = i; k <= j; k++){
				printf("%c", str[k]);
				}
		printf("\n");
		}
	}
}

int main()
{
    char inputStr[10];
    scanf("%s", inputStr);
    int len = strlen(inputStr);
    // Calculate total number of substrings
    int numSubstrings = len * (len + 1) / 2;
    // Allocate memory for array of substrings
    char ** allSubstrings = malloc(numSubstrings * sizeof(char*));
    
    // Access substrings from the array 
    printf("All substrings '%s' are : \n", inputStr);
    getAllSubstrings(inputStr, allSubstrings, len);
    
    // Using substrings array 
    for (int i = 0; i < numSubstrings; i++){
        printf("%s", allSubstrings[i]);
        printf("\n");
    }
       
    // Free memory
    for (int i=0; i < numSubstrings; i++){
        free(allSubstrings[i]);
    }
    free(allSubstrings);
    
    return 0;
}
