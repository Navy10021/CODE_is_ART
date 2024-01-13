// ~by YS
#include <stdio.h>
#include <string.h>

void swap(char *a, char *b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int isDuplicate(char * str, int st, int en){
    for (int i = st; i < en; i++){
        if (str[i] == str[en]){
            return 1;
        }
    }
    return 0;
}

int isPalindrome(char * str){
    int st = 0;
    int en = strlen(str) - 1;

    while(st < en){
        if (str[st] != str[en]){
            return 0;
        }
        st++;
        en--;
    }
    return 1;
}

void permutation(char *str, int l, int r){
    if (l == r && isPalindrome(str)){
        printf("%s\n", str);
    }

    else{
        for (int i = l; i <= r; i++){
            if(!isDuplicate(str, l, i)){
                swap((str + l), (str + i));
                permutation(str, l + 1, r);
                swap((str + l), (str + i));
            }
        }
    }
}

int main(void){
    char input[1000];
    scanf("%s", input);
    int n = strlen(input);

    permutation(input, 0, n - 1);
    return 0;
}
