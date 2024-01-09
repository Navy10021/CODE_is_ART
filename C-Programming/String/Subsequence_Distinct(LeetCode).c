#include <stdio.h>
#include <string.h>

// 115. Distinct Subsequences
// s = "rabbbit", t = "rabbit" -> 3가지 경우의 수로 삭제, t를 생성 / s = "badgbag", t = "bag" -> 5가지 경우의수로 삭제, t를 생성

void genSubseq(char *str, char *tgt, int index, char *subseq, int* count) {
    if (str[index] == '\0') {
        if (strcmp(subseq, tgt) == 0){
            //printf("%s\n", subseq);
            (*count)++;
            return;
        }
        return;  // Need to return!
    }
    // Exclude the current character
    genSubseq(str, tgt, index + 1, subseq, count);

    // Include the current character
    subseq[strlen(subseq)] = str[index];
    subseq[strlen(subseq) + 1] = '\0';
    genSubseq(str, tgt, index + 1, subseq, count);

    // Backtrack to exclude the current character
    subseq[strlen(subseq) - 1] = '\0';
}

int minDistinct(char * s, char * t) {
    int count = 0;
    char subseq[100] = "";
    genSubseq(s, t, 0, subseq, &count);

    return count;
}

int main(void) {
    char s[100];
    char t[100];
    scanf("%s %s", s, t);
    int res = minDistinct(s, t);
    printf("%d\n", res);

    return 0;
}
