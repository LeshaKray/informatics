#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

    push(stack** head, int v) {

	stack* s = (stack*)malloc(sizeof(stack)); 
	s->value = v; 
	s->next = *head; 
	*head = s;
}

int pop(stack** head)
{
	if (*head == NULL)
		return 0;
	else
	{
		stack* s = NULL;
		stack* p = NULL;
		p = *head;
		int result = p->value;
		*head = p->next;
		free(p);
		s = *head;
		return result;
	}
}
