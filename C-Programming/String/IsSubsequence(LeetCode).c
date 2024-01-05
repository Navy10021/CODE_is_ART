#include<stdio.h>
#include<string.h>

int isSubseq(const char *s, const char *t){
	int len1 = strlen(s);
	int len2 = strlen(t);
	
	int i = 0, j = 0;
	
	while(i < len1 && j < len2){
		if (s[i] == t[j]){
			i++;
		}
		j++;
	}
	return (i == len1);
}

int main(void){
	char s[100];
	char t[100];
	scanf("%s %s", s, t);
	
	int res = isSubseq(s,t); 
	if (res)
		printf("Is subsequnce.\n");
	else
		printf("Is NOT subsequence.\n");
	}