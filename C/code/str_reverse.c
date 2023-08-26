#include <stdio.h>
#include <string.h>

void reverseStr(char str[], int idx1, int idx2){
    while (idx1 < idx2){
        char temp = str[idx1];
        str[idx1] = str[idx2];
        str[idx2] = temp;
        idx1++;
        idx2--;
    }
}

int main(){
   char input_str[] = "Hello, World!";
   int idx_1 = 0;
   int idx_2 = 5;

   printf("Original string : %s\n", input_str);

   if (idx_1 < 0 || idx_2 < 0 || idx_1 >= strlen(input_str) || idx_2 >= strlen(input_str)){
    printf("Invalid \n");
   }
   else{
    reverseStr(input_str, idx_1, idx_2);
    printf("After reverse : %s\n", input_str);
   }

    return 0;
}
