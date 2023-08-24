#include <stdio.h>

char Score(int s){ // Change return type to char
    if (s >= 90 && s <= 100){
        return 'A';  // Use single quotes for char literals
    }

    else if (s >= 80 && s < 90){
        return 'B';
    }

    else if (s >= 70 && s < 80){
        return 'C';
    }

    else if (s >= 60 && s < 70){
        return 'D';
    }

    return 'F';
}

int main(){
    int A;

    printf("Enter your score: ");
    scanf("%d", &A);

    char result = Score(A); // Use char return type

    printf("Grade: %c\n", result); // Use %c for char
    return 0;
}
