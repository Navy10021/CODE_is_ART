# include<stdio.h>
# include<stdlib.h>
# include<string.h>

// 334. Increasing Triplet Subsequence.
int isIncrease(int *arr, int arrSize){
	for (int i = 1; i < arrSize; i++){
		if (arr[i-1] >= arr[i])
			return 0;
	}
	return 1;
}


void genSubseq(int *arr, int idx, int *subseq, int arrSize, int subSize, int* tgtLen, int* flag){
	if (idx == arrSize){
		if (subSize == (*tgtLen) && isIncrease(subseq, subSize)){
			*flag = 1;
			for (int i = 0; i < subSize; i++)
				printf("%d ", subseq[i]);
			printf("\n");
			return;
		}
		return;
	}
	// Exclude
	genSubseq(arr, idx + 1, subseq, arrSize, subSize, tgtLen, flag);
	// Include
	subseq[subSize++] = arr[idx];
	genSubseq(arr, idx + 1, subseq, arrSize, subSize, tgtLen, flag);
	// Backtrack
	subSize--;
}

int foo(int*arr, int arrSize){
	int tgtLen = 3;
	int flag = 0;
	int *subseq = (int *)malloc(arrSize * sizeof(int));
	genSubseq(arr, 0, subseq, arrSize, 0, &tgtLen, &flag);
	
	return flag;
}

int main(void){
	
	int arr[6] = {2,1,5,0,4,6};
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	int res = foo(arr, arrSize);
	
	if (res)
		printf("Is Triple Subseqence.\n");
	else 
		printf("Is NOT triple subsequence.\n");
	
	return 0;
	}
