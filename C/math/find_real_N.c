#include <stdio.h>

int main(){
	int total_divisor, num;
	int max = 0;
	int min = 100000;

	scanf("%d", &total_divisor);

	for (int i=0; i<total_divisor; i++){
		scanf("%d", &num);

		if (num > max){
			max = num;
		}
		if (num < min){
			min = num;
		}
	}
	printf("%d", min * max);
}
