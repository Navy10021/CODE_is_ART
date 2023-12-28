// 1. Check Can make Palindrome &&
// 2. Rearrange string to mak Palindrome.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int AnagramPalindrome(char str[]){
    int hash[52] = {0};

    for (int i = 0; i < strlen(str); i++){
        hash[str[i] - 'A']++;
    }

    int odd = 0;
    for (int i = 0; i < 52; i++){
        if (hash[i]%2 != 0)
            odd ++;

        if (odd > 1)
            return 0;
    }
    return 1;
}

void makePalindrome(char str[]){
    int hash[52] = {0};
    for (int i = 0; i < strlen(str); i++){
        hash[str[i] - 'A']++;
    }
    
    char * palin = (char*)malloc((strlen(str)+1) * sizeof(char));
    int idx = 0;
    char odd_char = '\0';
    for (int i = 0; i < 52; i++){
        if (hash[i] != 0){
            if (hash[i] % 2 == 0){ // even
                while(hash[i] > 0){
                    palin[idx++] = i + 'A';
                    hash[i] -= 2;
                }
            }
            else{ // odd
                if (hash[i] == 1)
                    odd_char = i + 'A';
                else{
                    while(hash[i] > 1){
                        palin[idx++] = i + 'A';
                        hash[i] -= 2;
                    }
                    odd_char = i + 'A';
                }
            }
        }
    }
    int rev_idx = idx - 1;
    if (odd_char){
        palin[idx++] = odd_char;
    }
    while(rev_idx >= 0){
        palin[idx++] = palin[rev_idx--];
    }
    palin[idx] = '\0';
        
    printf("%s\n", palin);
    free(palin);
}

int main(void){
    char str[50];
    scanf("%s", str);

    int res = AnagramPalindrome(str);
    if (res)
        printf("Can make palindrome.\n");
    else
        printf("Can NOT make palindrome.\n");

    if (res){
        makePalindrome(str);
    }
    return 0;
}
