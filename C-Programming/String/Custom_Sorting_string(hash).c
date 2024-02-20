#include <stdio.h>
#include <string.h>

void custom_sort(char* order, char* s){
    // 1. Build s-hash table 
    int hash[256] = {0};
    for (int i = 0; i < strlen(s); i++){
        hash[s[i]]++;
    }
    
    // 2. Make output
    char output[200];
    int output_idx = 0;
    
    // 3. Sort as per order
    for (int j = 0; j < strlen(order); j++){
        char curr_char = order[j];
        while(hash[curr_char] > 0){ // access hash directly
            output[output_idx++] = curr_char;
            hash[curr_char]--;
        }
    }
    
    // 4. Add rest characters
    for (int i = 0; i < 256; i++){
        while(hash[i] > 0){
            output[output_idx++] = i;
            hash[i]--;
        }
    }
    
    // 5. Convert to string
    output[output_idx] = '\0';
    printf("%s\n", output);
}

int main()
{
    char order[26];
    char s[200];
    
    scanf("%s %s", order, s);
    
    custom_sort(order, s);

    return 0;
}