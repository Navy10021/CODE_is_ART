# include<stdio.h>
# include<stdlib.h>
# include<string.h>

// 340. Longest Substring with At Most K Distinct Characters.
// s = "eceba", k = 2 -> output "ece" / length 3
// s = "aa", k = 1 -> output "aa" / length 2 

int isDistinct(char * str, int k){
	for(int i = 1; i < strlen(str); i++){
		if (abs((str[i-1] - str[i])) > k){
			return 0;
			}
		}
	return 1;
}

void longestSubstr(char * str, int k){
	int maxLen = 0;
	int length = strlen(str);
	
	for (int i = 0; i < length; i++){
		for (int j = i; j < length; j++){
			int subLen = j - i + 1;
			char* substr = malloc(sizeof(char)*(subLen+1));
			strncpy(substr, str+i, subLen);
			substr[subLen] = '\0';
			if (isDistinct(substr, k) && subLen > maxLen && subLen != 1){
				maxLen = subLen;
				printf("%s\n", substr);
				}
			free(substr);
			}
		}
	printf("The Longest k-Distinct substring : %d", maxLen);	
	return;
}

int main(void){
	char s[100];
	int k;
	scanf("%s %d", s, &k);
	longestSubstr(s, k);
	return 0;
}
