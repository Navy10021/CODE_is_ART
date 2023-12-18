#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* substr(const char *str, int start, int length) {
    // Copy the substring to the result array
    char *res = (char*)malloc(sizeof(char) * (length + 1));
    strncpy(res, str + start, length);
    res[length] = '\0';
    return res;
}

int main(void) {
    int N;
    char Time[6];
    int min, sec;
    int Team;
    int sum_a = 0, sum_b = 0;
    int score_a = 0, score_b = 0;
    int curr_time = 0;

    printf("Enter the number of iterations: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %s", &Team, Time);
        min = atoi(substr(Time, 0, 2));
        sec = atoi(substr(Time, 3, 2));

        if (score_a > score_b)
            sum_a += (min * 60) + sec - curr_time;
        else if (score_a < score_b)
            sum_b += (min * 60) + sec - curr_time;

        if (Team == 1)
            score_a++;
        else
            score_b++;

        curr_time = (min * 60) + sec;
    }

    if (score_a > score_b)
        sum_a += (48 * 60) - curr_time;
    else if (score_a < score_b)
        sum_b += (48 * 60) - curr_time;

    printf("%02d:%02d\n", sum_a / 60, sum_a % 60);
    printf("%02d:%02d\n", sum_b / 60, sum_b % 60);

    return 0;
}