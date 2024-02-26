#include <stdio.h>
#include <string.h>
#include <math.h>

// Mininum Cost Convert to string Palindrome.

int min(int a, int b){
    return (a < b) ? a : b;
}

int minCost_palindrome(char str[]){
    int st = 0;
    int en = strlen(str) - 1;
    int cost = 0;

    while (st < en){
        if (str[st] != str[en]){
            //cost += min(str[st] - 'a', str[en] - 'a') + 1;
            cost += abs(str[st] - str[en]);
            if (str[st] > str[en])
                str[en] = str[st];
            else 
                str[st] = str[en];
        }
        st++;
        en--;
    }
    printf("Replaced string : %s\n", str);
    printf("Minimum Cost to replace : %d\n", cost);
    return cost;
}

int main(void){
    char input[50];
    scanf("%s", input);
    int res = minCost_palindrome(input);

    return 0;
}
