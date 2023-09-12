#include <stdio.h>
#include <string.h>
#include <ctype.h>

int areAnagrams(const char *str1, const char *str2) {
    int charCount1[26] = {0};
    int charCount2[26] = {0};
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    if (len1 != len2) {
        return 0; // Different lengths cannot be anagrams
    }
    
    for (int i = 0; i < len1; i++) {
        char c1 = tolower(str1[i]);
        char c2 = tolower(str2[i]);
        
        charCount1[c1 - 'a']++;
        charCount2[c2 - 'a']++;
    }
    
    for (int i = 0; i < 26; i++) {
        if (charCount1[i] != charCount2[i]) {
            return 0; // Character counts don't match
        }
    }
    
    return 1; // Anagrams
}

int main() {
    const char *word1 = "listen";
    const char *word2 = "silent";
    
    if (areAnagrams(word1, word2)) {
        printf("%s and %s are anagrams.\n", word1, word2);
    } else {
        printf("%s and %s are not anagrams.\n", word1, word2);
    }
    
    return 0;
}
