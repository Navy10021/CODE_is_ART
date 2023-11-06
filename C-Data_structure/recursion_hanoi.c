#include <stdio.h>

int cnt = 0;
void hanoi(int n, char from, char by, char to){ // A -> C;  
    if (n == 1){
        printf("1 : %c -> %c\n", from, to);
        cnt++;
    }
    else{
        hanoi(n-1, from, to, by);    // A -> B;  1 -> C;
        printf("%d : %c -> %c\n", n, from, to);
        cnt++;
        hanoi(n-1, by, from, to);    // B -> C;
    }
}

int main(void){
    int n = 3;
    hanoi(3, 'A', 'B', 'C');
    printf("Count : %d\n", cnt);
}
