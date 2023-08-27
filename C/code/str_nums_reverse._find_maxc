#include <stdio.h>
#include <string.h>

void reverse(char str[]){
    int len = strlen(str);

    for (int i=0; i<len/2; i++){
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int find_max(int a, int b){
    if (a > b){
        return a;
        }
    else{
        return b;
    }
}

int main(){
    char num_1[5];
    char num_2[5];

    scanf("%s %s", num_1, num_2);
    
    reverse(num_1);
    reverse(num_2);

    int a = atoi(num_1);
    int b = atoi(num_2);

    printf("%d", find_max(a, b));


}
