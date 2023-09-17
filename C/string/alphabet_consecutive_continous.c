#include <stdio.h>
#include <stdbool.h>

bool areAdjacentContinuous(const char *str) {
    if (str == NULL || str[0] == '\0') {
        return false; // Empty or null string is not continuous.
    }

    for (int i = 0; str[i + 1] != '\0'; i++) {
        if (str[i + 1] != str[i] + 1) {
            return false; // Characters are not continuous.
        }
    }

    return true; // Characters are continuous.
}

bool areAdjacentConsecutive(const char *str) {
    if (str == NULL || str[0] == '\0') {
        return false; // Empty or null string is not continuous.
    }

    for (int i = 0; str[i + 1] != '\0'; i++) {
        if (str[i + 1] == str[i] + 1 || str[i + 1] == str[i] - 1) {
            return true; // Characters are not continuous.
        }
    }

    return false; // Characters are continuous.
}


int main() {
    const char *input = "bac";
    
    if (areAdjacentContinuous(input)) {
        printf("Adjacent characters are continuous.\n");
    } else {
        printf("Adjacent characters are NOT continuous.\n");
    }
    if (areAdjacentConsecutive(input)){
        printf("Adjacent characters are Consecutive.\n");
    } else {
        printf("Adjacent characters are NOT Consecutive.\n");
    }
    return 0;
}
