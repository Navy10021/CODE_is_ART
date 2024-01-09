#include <stdio.h>
#include <string.h>

// 345. Reverse Vowels of a string : The vowels are 'a', 'e', 'i', 'o', 'u' -> reverse
// hello -> holle / leetcode -> leotecede

int is_aeiou(char c){
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return 1;
    return 0;
}

void swap(char * str, int i, int j){
    char temp;
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

void reverseVowels(char * s){
    int st = 0;
    int en = strlen(s) - 1;

    while(st < en){
        if(is_aeiou(s[st]) && is_aeiou(s[en])){
            swap(s, st, en);
            st++;
            en--;
        }
        
        else if (is_aeiou(s[st]) && !is_aeiou(s[en]))
            en--;
        
        else if (!is_aeiou(s[st]) && is_aeiou(s[en]))
            st++;

        else{
            st++;
            en--;
        }
    }
    printf("%s\n", s);
}

int main(void){
    //char input[] = "leetcode";
    char input[100];
    scanf("%s", input);
    reverseVowels(input);
}
