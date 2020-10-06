#include "header.h"

int* counter(int n) {
	int *arr = (int *)calloc(10, sizeof(int));

	//오류
	if(arr == NULL) {
		fprintf(stderr, "Memory allocation error\n");
		exit(-1);
	}

	for(int i = 1; i <= n; i++) {
		int t = i;
		while(t) {//1의 자리부터 오름자릿순으로  추가하기, 모두 계산하면 탈출
			arr[t%10]++;
		t /= 10;//다음자리
		}
	}

	return arr;
}
