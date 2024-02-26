#include <stdio.h>
#include <stdlib.h>

// 2진 -> 10진으로 변경하는 함수
int binaryToDecimal(char* binaryString) {
    int decimalNumber = 0;
    int i = 0;

    while (binaryString[i] != '\0') {
        decimalNumber = decimalNumber * 2 + (binaryString[i] - '0');
        ++i;
    }

    return decimalNumber;
}

// Assuming a maximum number of combinations for simplicity
#define MAX_COMBINATIONS 100

// Bits combinations. n진수로 가능한 비트 생성
void generateCombinations(int n, int r, int* outputArray, int* outputSize) {
    *outputSize = 0; // Initialize the size of output array
    for (int i = 0; i < (1 << n); i++) {
        int count = 0;
        char combination[n + 1]; // +1 for null terminator
        combination[n] = '\0';   // Null-terminate the string

        for (int j = 0; j < n; j++) {
            if (i & (1 << (n - 1 - j))) {
                combination[j] = '1';
                count++;
            } else {
                combination[j] = '0';
            }
        }

        if (count == r) {
            int num = binaryToDecimal(combination);
            if (*outputSize < MAX_COMBINATIONS) {
                outputArray[*outputSize] = num;
                (*outputSize)++;
            }
        }
    }
}

// leetcode 401. Binary Watch.
void binaryWatch(int turnOn){
    int h_combination[MAX_COMBINATIONS];
    int m_combination[MAX_COMBINATIONS];
    int h_size;
    int m_size;
    printf("{");
    for (int h = 0; h < 4; h++){        // hour 4 bits
        for (int m = 0; m < 6; m++){    // minitue 6 bits
            if (h + m == turnOn){
                generateCombinations(4, h, h_combination, &h_size);
                generateCombinations(6, m, m_combination, &m_size);
                for(int i = 0; i < h_size; i++){
                    for (int j = 0; j < m_size; j++){
                        printf("%d:%02d, ", h_combination[i], m_combination[j]);
                    }
                }
            }
        }
    }
    printf("}");
}

int main() {
    int turnedOn;
    scanf("%d", &turnedOn);
    binaryWatch(turnedOn);

    return 0;
}