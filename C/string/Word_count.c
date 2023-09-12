#include <stdio.h>
#include <ctype.h> // for isalpha
#include <string.h>

#define MAX_WORDS 100

struct WordCount{
    char word[MAX_WORDS];
    int cnt;
};

// 딕션어리, 단어가 채워질 인덱스, 입력 단어
void addToDict(struct WordCount dictionary[], int *numWords, const char *word){
    for (int i = 0; i < *numWords; i++){
        if (strcmp(dictionary[i].word, word) == 0){
            dictionary[i].cnt++;
            return;
        }
    }
    // 딕션어리에 단어가 없는 경우
    if (*numWords < MAX_WORDS){
        strcpy(dictionary[*numWords].word, word);   // 단어 카피해서 넣기
        dictionary[*numWords].cnt = 1;              // 단어 개수 1
        (*numWords)++;                                // 저장 인덱스+=1
    }
}

int main(){
    char inputText[] = "Never give up. never ever lose yourself. You don't have right to give up. You don't have right to throw away your talent.";
    
    struct WordCount dictionary[MAX_WORDS];
    int numWords = 0;
    
    char *token = strtok(inputText, " .!?,"); // 공백과 구두점 기준으로 토크나이즈
    while (token != NULL && numWords < MAX_WORDS){
        for (int i = 0; token[i]; i++){
            token[i] = tolower(token[i]);   // 소문자 변환
        }
        addToDict(dictionary, &numWords, token);
        token = strtok(NULL, " .!?,");
    }

    // 출력
    for (int i = 0; i < numWords; i++){
        printf("%s : %d\n", dictionary[i].word, dictionary[i].cnt);
    }

    return 0;
}
