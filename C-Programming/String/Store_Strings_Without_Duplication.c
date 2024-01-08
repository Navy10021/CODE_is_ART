#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isIn(char ** strings, int currIdx, const char * val){
    for (int i = 0; i < currIdx; i++){
        if (strcmp(strings[i], val) == 0)
            return 1;
    }
    return 0;
}

int main(void){

    const char* temp[] = {"C", "C++", "JAVA", "Python", "C++", "C"};
    
    //char ** strings = (char**)malloc(100 * sizeof(char*));
    char ** strings = NULL;
    int currIdx = 0;

    for (int i = 0; i < 6; i++){
        if(!isIn(strings, currIdx, temp[i])){
            //strings[currIdx++] = strdup(temp[i]);
            strings = (char**)realloc(strings, (currIdx + 1) * sizeof(char));
            strings[currIdx++] = strdup(temp[i]);
        }
    }

    // Print No duplication elements
    for (int i = 0; i < currIdx; i++){
        printf("%s, ", strings[i]);
    }

    for (int i = 0; i < currIdx; i++){
        free(strings[i]);
    }
    free(strings);

}
