#include <stdio.h>
#include <stdbool.h>

int countWords(const char *str){
    bool in_word = false;
    int word_cnt = 0;

    for (int i=0; str[i] != '\0'; i++){
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'){
            if (!in_word){
                in_word = true;
                word_cnt++;
            }
        }
        else{
            in_word = false;
            }
        }
        return word_cnt;
}

int main(){
    char str[1000];
    scanf("%[^\n]", str);
    
    int words = countWords(str);
    printf("Number of words : %d\n", words);
    return 0;
}
