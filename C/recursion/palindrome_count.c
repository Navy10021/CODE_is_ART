#include <stdio.h>
#include <string.h>

int cnt;

int recursion(const char *s, int l, int r){
    cnt++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else{
        return recursion(s, l+1, r-1);
        }
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(){
    int T, res;
    scanf("%d", &T);
    char str[1000];
    while(T--){
        cnt = 0;
        scanf("%s", str);
        res = isPalindrome(str);
        printf("%d %d\n", res, cnt);
    }
    return 0;
}
