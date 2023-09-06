#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
 
int main() {
	int N, K, i, cnt, max = 0;
	long long mid;
	scanf("%d %d", &N, &K);
	int* arr = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] > max)
			max = arr[i];
	}
 
	long long left, right, ans = 0;
	left = 1;
	right = max;
 
	while (left <= right) {
		mid = (left + right) / 2;
		cnt = 0;
		for (i = 0; i < N; i++)
			cnt += arr[i] / mid;
		
		if (cnt >= K) {
			if (ans < mid)
				ans = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	printf("%lld", ans);
	free(arr);
	return 0;
}
