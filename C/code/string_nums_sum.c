#include <stdio.h>

int main(){
   int length, sum = 0;
   char nums[100];

   scanf("%d", &length);
   scanf("%s", nums);

   for (int i = 0; i < length; i++){
    sum += nums[i] - '0';   // char -> int
   }
   
   printf("%d\n", sum);

   return 0;
}
