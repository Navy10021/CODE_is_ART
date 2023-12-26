#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void find_word(char * str, char * target, int arr[], int * arrNum){
    int word_len = 0;
    int word_idx = 0;
    int word_count = -1;
    for (int idx = 0; idx < strlen(str); idx++){
        char c = str[idx];
        if (isspace(c) || c == '.' || c == ','){
            if (word_len > 0){
                word_count++;
                char *word = (char *)malloc(sizeof(char) * (word_len + 1));
                for (int i = 0; i < word_len; i++){
                    word[i] = tolower(str[word_idx++]);
                }
                word[word_len] = '\0';
                if(strcmp(target, word) == 0){
                    arr[(*arrNum)++] = word_count;
                }
                free(word);
                word_len = 0;
                word_idx = idx + 1;
            }
            else{
                word_idx++;    // Skip consecutive whitespace or puntuation.
            }
        }
        else{
            word_len++;
        }
    }
    
}

void ToLower(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

int main(void){
    char intput_s[] = "Some feelings are shallow, some feelings are deep. Some make us smile, some make us weep.";
    char target_s[] = "Feelings";
    // make lowwer
    ToLower(target_s);
    ToLower(intput_s);

    int arr[100];
    int arrNum = 0;
    find_word(intput_s, target_s, arr, &arrNum);
    printf("[");
    for(int i = 0; i < arrNum; i++){
        if (i == arrNum - 1)
            printf("%d", arr[i]);
        else
            printf("%d, ", arr[i]);
    }
    printf("]");

    return 0;
}
