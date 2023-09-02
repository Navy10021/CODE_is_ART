#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store a word and its frequency
struct WordInfo {
    char word[100];
    int frequency;
};

// Comparison function for sorting
int compare(const void* a, const void* b) {
    struct WordInfo* wordInfoA = (struct WordInfo*)a;
    struct WordInfo* wordInfoB = (struct WordInfo*)b;

    // 1. Sort by frequency (high to low)
    if (wordInfoA->frequency != wordInfoB->frequency) {
        return wordInfoB->frequency - wordInfoA->frequency;
    }
    // 2. Sort by length (longest to shortest)
    else if (strlen(wordInfoA->word) != strlen(wordInfoB->word)) {
        return strlen(wordInfoB->word) - strlen(wordInfoA->word);
    }
    // 3. Sort lexicographically
    else {
        return strcmp(wordInfoA->word, wordInfoB->word);
    }
}

int main() {
    int num_words, min_length;
    scanf("%d %d", &num_words, &min_length);

    struct WordInfo wordInfoArray[1000];
    int wordCount = 0;

    while (num_words--) {
        char word[100];
        scanf("%s", word);

        // Check if the word length is greater than or equal to min_length
        if (strlen(word) >= min_length) {
            int found = 0;
            // Check if the word is already in the array and update its frequency
            for (int i = 0; i < wordCount; i++) {
                if (strcmp(wordInfoArray[i].word, word) == 0) {
                    wordInfoArray[i].frequency++;
                    found = 1;
                    break;
                }
            }
            // If not found, add it to the array
            if (!found) {
                strcpy(wordInfoArray[wordCount].word, word);
                wordInfoArray[wordCount].frequency = 1;
                wordCount++;
            }
        }
    }

    // Sort the array based on the defined comparison function
    qsort(wordInfoArray, wordCount, sizeof(struct WordInfo), compare);

    // Output the sorted words
    for (int i = 0; i < wordCount; i++) {
        printf("%s (%d)\n", wordInfoArray[i].word, wordInfoArray[i].frequency);
    }

    return 0;
}
