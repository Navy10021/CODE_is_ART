// print all combination

#include <stdio.h>
#include <string.h>

void generateCombinations(char *str, int start, int length, char *output, int index) {
    if (index == length) {
        output[index] = '\0';
        printf("%s\n", output);
        return;
    }

    if (start >= strlen(str)) {
        return;
    }

    // Include the current character in the combination
    output[index] = str[start];
    generateCombinations(str, start + 1, length, output, index + 1);

    // Exclude the current character from the combination
    generateCombinations(str, start + 1, length, output, index);
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    int length = strlen(input);

    for (int len = 1; len <= length; len++) {  // 1~length 단어의 조합
        char combination[len + 1];
        generateCombinations(input, 0, len, combination, 0);
    }

    return 0;
}

