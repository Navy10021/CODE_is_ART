#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num){
    if (num <= 1){
        return false;
    }

    for (int i=2; i*i <= num; i++){
        if (num % i == 0){
            return false;
        }
    }
    return true;
}

void findPrimeInArray(int arr[], int size){
    for (int i=0; i<size; i++){
        if (isPrime(arr[i])){
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main(){
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];

    printf("Enter %d elements : \n", size);
    for (int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    findPrimeInArray(arr, size);

    return 0;
}
