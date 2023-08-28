#include <stdio.h>
#include <string.h>

int main(){
    int n, res = 0;
    scanf("%d", &n);
    while (n--)
    {
        // Compress continuous alphabet : 연속되는 단어 압축
        char str[101] = {NULL,};
        char compress[101] = {NULL,};
        scanf("%s", str);
        compress[0] = str[0];
        int j = 1;
        for (int i=1; i < strlen(str); i++){
            if (str[i] == str[i-1]){
                continue;
            }
            else{
                compress[j++] = str[i];
            }
        }
        printf("Compressed str : %s \n", compress);

        if (strlen(compress) == 1) res++;
        else{
            // check group alphabets : 한번 사용된 알파벳이 또 나오는 경우 확인
            int flag = 1;
            for(int i=0; i<strlen(compress); i++){
                for(int j=i+1; j<strlen(compress); j++){
                    if (compress[i] == compress[j]){
                        flag = 0;
                        break;
                    }
                }
            }
            res += flag;
        }
    }
    printf("%d", res);
}
