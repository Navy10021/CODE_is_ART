#include <stdio.h>
#include <string.h>

void remove_duplicate(char str[], int size){
    
    // make hash table
    int hash[26];
    for (int i = 0; i < 26; i++){
        hash[i] = 0;
    }
    // insert alphabets
    for (int i = 0; i < size; i++){
        hash[str[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++){
        if (hash[i] != 0)
            printf("%c", i + 'a');
    }
}

int main(){
    char string[] = "aaabbbcccddd";
    int size = sizeof(string) / sizeof(string[0]);
    remove_duplicate(string, size);
}


