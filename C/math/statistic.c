#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to compare two integers for sorting
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N;
    scanf("%d", &N);

    int numbers[N];
    int freq[10001] = {0}; // Assuming numbers are within the range [0, 10000]
    int sum = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
        sum += numbers[i];
        freq[numbers[i]]++;
    }

    // 1. 산술평균
    double mean = (double)sum / N;
    int rounded_mean = round(mean); 

    // 2. 중앙값 (numbers 배열을 정렬하여 계산)
    qsort(numbers, N, sizeof(int), compare);
    int median = numbers[N / 2];

    // 3. 최빈값
    int max_cnt = 0;    // 최빈값 빈도수
    int curr_cnt = 0;   // 현재 빈도수 
    int modes[N];       // 최빈값 저장 array

    for (int i=0; i<N; i++){
        curr_cnt = 0;
        for (int j=0; j<N; j++){
            if (numbers[i] == numbers[j]){
                curr_cnt++;
            }
        }
        // 현재 빈도수가 최빈값 보다 큰 경우, 업데이트&&최빈값 저장배열 초기화
        if (curr_cnt > max_cnt){
            max_cnt = curr_cnt;
            modes[0] = numbers[i];
            for (int j = 1; j < N; j++){
                modes[j] = 0;
            }
        }
        // 현재 빈도수가 최빈값과 같은경우 최빈값 배열에 현재값 추가
        else if (curr_cnt == max_cnt){
            for (int j = 0; j < N; j++){
                if(modes[j] == 0){
                    modes[j] = numbers[i];
                    break;
                }
            }
        }
    }


    // 4. 범위 구하기
    int min = numbers[0];
    int max = numbers[N - 1];
    int mode = modes[1]!=0 ? modes[1] : modes[0]; 
    int range = max - min;

    // 결과 출력
    printf("==================\n");
    printf("%d\n", rounded_mean);
    printf("%d\n", median);
    printf("%d\n", mode);
    printf("%d\n", range);

    return 0;
}
