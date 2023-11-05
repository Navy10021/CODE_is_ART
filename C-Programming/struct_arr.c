#include <stdio.h>
#include <string.h>

struct employee{
    char name[10];
    char ip[15];
    int payment;
};

int main()
{   
    // 길이 3인 구조체 기반 배열 
    struct employee arr[3];
    
    for (int i = 0; i < 3; i++){
        printf("Name : "); scanf("%s", arr[i].name);
        printf("IP : "); scanf("%s", arr[i].ip);
        printf("Pay : "); scanf("%d", &arr[i].payment);
    }
    
    // 배열 출력 
    for (int i = 0; i < 3; i++){
        printf("Employee %d : (Name) %s | (IP) %s | (Payment) %d \n", i+1, arr[i].name, arr[i].ip, arr[i].payment);
    }
    return 0;
}
