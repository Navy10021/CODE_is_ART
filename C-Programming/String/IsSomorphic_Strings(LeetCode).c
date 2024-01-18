#include <stdio.h>
#include <stdbool.h>

bool isIsomorphic(char *s, char *t) {
    char sToT[256] = {0};
    char tToS[256] = {0};

    while (*s != '\0') {
        if (sToT[*s] == 0 && tToS[*t] == 0) {
            sToT[*s] = *t;
            tToS[*t] = *s;
        } else {
            if (sToT[*s] != *t || tToS[*t] != *s) {
                return false;
            }
        }

        s++;
        t++;
    }

    return true;
}

int main(void) {
    char s[100], t[100];
    scanf("%s %s", s, t);

    bool res = isIsomorphic(s, t);
    printf("%d", res);

    return 0;
}