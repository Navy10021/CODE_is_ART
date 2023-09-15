#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store a word and its frequency
struct Word {
    char word[100];
    int frequency;
};

int main() {
    int num_words;
    scanf("%d", &num_words);

    struct Word wordArr[1000];
    int wordCount = 0;  // Array에 저장된 단어 개수

    while (num_words--) {
        char word[100];
        scanf("%s", word);
        
        // struct에 해당단어가 있는지 여부 확인
        int found = 0;
        // 1. 해당 단어가 wordArr 존재하는지 확인 및 빈도 업데이트
        for (int i=0; i<wordCount; i++){
            if (strcmp(wordArr[i].word, word)==0){  // 존재하면,
                wordArr[i].frequency++;             // 빈도수 업데이트
                found = 1;
                break;
            }
        }
        // 2. 없으면, wordArr에 추가 및 단어개수++(Array Size)
        if (!found){
            strcpy(wordArr[wordCount].word, word);
            wordArr[wordCount].frequency = 1;
            wordCount++;
            }
        // 출력
        }
    for (int i=0; i<wordCount; i++){
        printf("%s (%d)\n", wordArr[i].word, wordArr[i].frequency); 
    }
    return 0;
}
