#include <stdio.h>
#include <string.h>

int findCharIdx(const char * str, char target, int * arr){
    const char * pos = str;
    int idx = 0;
		// strchr() : string 내 target char의 첫번째 인덱스(위치)를 반환
		// While문을 통해 모든 인덱스를 arr에 저장
    while((pos = strchr(pos, target)) != NULL){
        //printf("%ld ", pos - str);
        arr[idx++] = pos - str;
        pos++;
    }
    return idx;
}

int main(){
    char input[20] = "Lee Yoon Seop";
    char target = ' ';
    int arr[20];
    
    int count = findCharIdx(input, target, arr);
    //printf("%d", count);
    
    for (int i = 0; i < count; i++){
        printf("%d ", arr[i]);
    }
    
    return 0;
}
