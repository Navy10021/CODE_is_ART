#include <stdio.h>
#include <string.h>
/*
그룹 단어란 단어에 존재하는 모든 문자에 대해서, 각 문자가 연속해서 나타나는 경우만을 말한다. 
예를 들면, ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나고, kin도 k, i, n이 연속해서 나타나기 때문에 그룹 단어이지만,
aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.
n개 중 그룹단어 개수 출력
*/
int main(){
    int n, res = 0;
    scanf("%d", &n);
    while (n--)
    {
        // 1.Compress continuous alphabet : 연속되는 단어 압축
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
            // 2.check group alphabets : 한번 사용된 알파벳이 또 나오는 경우 확인
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
