#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

void removePunctuation(char* word) {
    int len = strlen(word);
    int i, j = 0;
    
    for (i = 0; i < len; i++) {
        if (!ispunct(word[i])) {
            word[j++] = word[i];
        }
    }
    word[j] = '\0';
}

void countWordFreq(char* str) {
    char wordFrequncy[MAX_WORDS][2][MAX_WORD_LENGTH]; // [0]: word, [1]: frequency
    int totalWords = 0;

    char* token = strtok(str, " ");
    while (token != NULL) {
        removePunctuation(token);
        if (strlen(token) > 0) {
            int found = -1;
            for (int i = 0; i < totalWords; i++) {
                if (strcmp(wordFrequncy[i][0], token) == 0) {   // WordFreq에 존재하면, found = i;
                    found = i;
                    break;
                }
            }
            if (found == -1) {
                strcpy(wordFrequncy[totalWords][0], token); // token을 wordFreq[totalwords][0]로 복사
                strcpy(wordFrequncy[totalWords][1], "1");   // "1"을 복사
                totalWords++;
            } else {
                int freq = atoi(wordFrequncy[found][1]) + 1;    // 문자열 -> 정수로 변환
                sprintf(wordFrequncy[found][1], "%d", freq);    // str 문자열에 "freq" 저장
            }
        }
        token = strtok(NULL, " ");
    }
    printf("Total number of words: %d\n", totalWords);

    for (int i = 0; i < totalWords; i++) {
        char* freqDescription;
        if (strcmp(wordFrequncy[i][1], "1") == 0) {
            freqDescription = "once";
        } else if (strcmp(wordFrequncy[i][1], "2") == 0) {
            freqDescription = "twice";
        } else {
            freqDescription = "times";
        }

        printf("Word %s appears %s %s\n", wordFrequncy[i][0], wordFrequncy[i][1], freqDescription);
    }
}

int main() {
    char given_str[] = "Doubt thou the stars are fire Doubt that the sun doth move. Doubt truth to be a liar. But never dout I love.";
    countWordFreq(given_str);

    return 0;
}
