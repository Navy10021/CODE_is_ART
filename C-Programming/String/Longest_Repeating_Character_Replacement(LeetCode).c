#include<stdio.h>
#include <stdlib.h>
#include<string.h>

// 424. Longest Repeating Character Replacement.
// Retrun the length of the longest substring containing the same letter.
// Solution : substring -> check Can replacement with k-th -> update

int Canreplace(char* str, int k){
	int hash[26] = {0};
	for (int i = 0; i < strlen(str); i++){
		hash[str[i] - 'A']++;
		}
	
	int maxFreq = 0;
	char highFreqChar;
	for (int i = 0; i < 26; i++){
		if (maxFreq < hash[i]){
			maxFreq = hash[i];
			highFreqChar = i + 'A';	
		}
	}
	if ((maxFreq + k) >= strlen(str))
		return 1;
	
	return 0;
}

void longSubstr(char * str, int k){
	int maxLen = 0;
	int length = strlen(str);
	
	for (int i = 0; i < length; i++){
		for (int j = i; j < length; j++){
			int subLen = j - i + 1;
			char* substr = (int *)malloc(sizeof(char) * (subLen+1));
			strncpy(substr, str+i, subLen);
			substr[subLen] = '\0';
			if (Canreplace(substr, k) && subLen > maxLen){
				printf("%s\n",substr);
				maxLen = subLen;
				}
			free(substr);
			}
		
		}
	printf("Max Length with k-replacement : %d", maxLen);
	}


int main(void){
	char input[100];
	int k;
	scanf("%s %d", input, &k);
	
	longSubstr(input, k);
	return 0;
	}