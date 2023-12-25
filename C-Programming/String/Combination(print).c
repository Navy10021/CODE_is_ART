#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void genCombinations(char * str, char * buffer, int start, int depth){
    int len = strlen(str);
    
    if (depth == 0){ // 요구하는 길이와 일치하면 프린트
        printf("%s\n", buffer);
        return;
    }
    for (int i = start; i < len; i++){
	  //for (int i = start; i < len - depth; i++){// No duplication
        buffer[depth - 1] = str[i];  // 해당 문자열의 문자 저장
        genCombinations(str, buffer, i+1, depth-1);
    }
}

int main(){
    char input[] = "ABC";
    int length = strlen(input);
    
    for (int depth = 1; depth <= length; depth++){
        char combinationBuffer[depth + 1];
        combinationBuffer[depth] = '\0'; // NULL-terimnate
        
        printf("Combination of lenght : %d\n", depth);
        genCombinations(input, combinationBuffer, 0, depth);
        printf("\n");
    }
    return 0;
}
