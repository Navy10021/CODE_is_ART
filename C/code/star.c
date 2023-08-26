#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);

    for (int k = 1; k <= N; k++){
        // print space
        for (int i=1; i<=N-k; i++){
            printf(" ");
        }
        // print star
        for (int j=1; j<=k; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
