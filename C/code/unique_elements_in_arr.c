#include <stdio.h>

int main(){
    int num, size = 10;
    int arr[size];

    // elements input and store the rest
    for (int i = 0; i < size; i++){
        scanf("%d", &num);
        arr[i] = num % 42;
    }
    // count different elements
    int cnt = 0;
    int unique_arr[size];

    for (int i = 0; i < size; i++){
        int is_unique = 1;  // 고유한 요소(True)

        for (int j = 0; j < cnt; j++){
            if (arr[i] == unique_arr[j]){   // unique_arr를 순회하며 존재하면 false;
                is_unique = 0;  // False
                break;
            }
        }
        if (is_unique){
            unique_arr[cnt] = arr[i];
            cnt++;
        }
    }
    
    printf("Unique elements : %d\n", cnt);

    
    return 0;
}
