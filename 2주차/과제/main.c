#include "header.h"

int main(void) {
	int tc;//test cases
	int i;
	scanf("%d",&tc);
	
	int n[tc];
	for(i=0; i<tc; i++){
		scanf("%d",&(n[i]));
	}

	for(i=0; i<tc; i++){
		int* ans = counter(n[i]);
		print_answer(ans,stdout);
		free(ans);
	}
	return 0;
}
