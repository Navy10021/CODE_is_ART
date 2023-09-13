#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 10

char str[MAX_N];
int arr[MAX_N];
bool is_used[MAX_N];
int N, M;

void func(int k) {
    if (k == M) {
        for (int i = 0; i < M; i++) {
            printf("%c ", str[arr[i]]);
        }
        printf("\n");
        return;
    }

    int st = 0;
    if (k != 0) st = arr[k - 1] + 1;

    for (int i = st; i < N; i++) {
        if (!is_used[i]) {
            arr[k] = i;
            is_used[i] = true;
            func(k + 1);
            is_used[i] = false;
        }
    }
}

int main(void) {
    strcpy(str, "DBCA");
    M = 3;
    N = strlen(str);
    // initalize
    for (int i = 0; i < N; i++) {
        is_used[i] = false;
    }
    // sorting
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    func(0);
    return 0;
}
