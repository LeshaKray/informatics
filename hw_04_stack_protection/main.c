#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
int main(void) {
	stack* s = NULL; 
	int v;
	scanf("%d", &v);

	while (v != -1) { 
		if (v % 2) 
			push(&s, v); 

		scanf("%d", &v);
	}

	while (s) 
		printf("%d ", pop(&s)); 

	return 0;
}