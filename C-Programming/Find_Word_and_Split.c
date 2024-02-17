#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Split function
char** split(const char *str, char delimiter, int *count) {
    // Count the number of occurrences of the delimiter for array size
    *count = 1;
    for (const char *ptr = str; *ptr != '\0'; ptr++) {
        if (*ptr == delimiter) {
            (*count)++;
        }
    }

    // Allocate memory for the array of string
    char** res = (char**)malloc((*count) * sizeof(char*));
    if (res == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    // Copy substrings into the array
    int idx = 0;
    const char *start = str;
    for (const char *ptr = str; *ptr != '\0'; ptr++) {
        if (*ptr == delimiter) {
            // Memory allocation for substring
            res[idx] = (char*)malloc((ptr - start + 1) * sizeof(char));
            if (res[idx] == NULL) {
                fprintf(stderr, "Memory allocation error\n");
                // Free memory allocated so far
                for (int i = 0; i < idx; ++i) {
                    free(res[i]);
                }
                free(res);
                exit(EXIT_FAILURE);
            }
            // Copy
            strncpy(res[idx], start, ptr - start);
            res[idx][ptr - start] = '\0';   // NULL-terminate the substring
            // Move to the next substring
            start = ptr + 1;
            idx++;
        }
    }

    // Handle the last substring('\0')
    res[idx] = (char*)malloc((str + strlen(str) - start + 1) * sizeof(char));
    if (res[idx] == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        // Free memory allocated so far
        for (int i = 0; i <= idx; ++i) {
            free(res[i]);
        }
        free(res);
        exit(EXIT_FAILURE);
    }
    // Copy the last substring
    strcpy(res[idx], start);

    return res;
}

// Replace function
void replace(char * str, char target, char replacement){
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == target){
            str[i] = replacement;
        }
    }
}

// Erase function
void erase(char * str, char target){
    int len = strlen(str);
    int i, j;
    for (i = 0, j = 0; i < len; i++){
        if (str[i] != target){
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

int main(void) {
    char input[] = "Some feelings are shallow, some feelings are deep. Some make us smile, some make us weep.";
    // 1.erase
    char erase_target;
    erase_target = ',';
    erase(input, erase_target);
    erase_target = '.';
    erase(input, erase_target);

    // 2.Split the string
    char delimiter = ' ';
    int count;
    char** arr = split(input, delimiter, &count);

    // 3.Print
    /*
    for (int i = 0; i < count; i++) {
        printf("Token %d: %s\n", i + 1, arr[i]);
    }
    */

    // 4. Compare token and target word.
    char tgt_word[] = "Some";
    printf("[ ");
    for (int i = 0; i < count; i++){
        if(strcasecmp(arr[i], tgt_word) == 0)
            printf("%d ", i);
    }
    printf("]");
    
    // Memory free
    for (int i = 0; i < count; ++i) {
        free(arr[i]);
    }
    free(arr);
    
    return 0;
}
