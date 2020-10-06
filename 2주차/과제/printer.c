#include "header.h"

void print_answer(int *arr,  FILE* fp) {

	//예외처리
	if(fp == NULL) {
		return;
	}

	for(int i = 0; i < 10; i++) {
		fprintf(fp, "%d ", arr[i]);
	}
	putc('\n', fp);
}

