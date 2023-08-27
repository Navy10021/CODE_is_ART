#include <stdio.h>
#include <string.h>

int main(){
   char str[100];
   int alphabet[26];
   
   scanf("%s", str);
   int length = strlen(str);

   // Initalize the alphhabet array to -1
   for (int i = 0; i < 26; i++){
    alphabet[i] = -1;
   }

   for (int i=0; i<length; i++){
    if (str[i] >='a' && str[i] <= "z"){
        if (alphabet[str[i]-'a'] == -1) alphabet[str[i] - 'a'] = i; // 알파벳이 처음 등장하는 위치만 업데이트
    }
  }

  for (int i = 0; i < 26; i++){
    printf("%d ", alphabet[i]);
  }

   return 0;
}
