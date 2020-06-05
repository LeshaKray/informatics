#ifndef STACK_H
#define STACK_H
struct stack
{
	char value;
	struct stack* next;
};
typedef struct stack stack;
push(stack** head, const char str);
int pop(stack** head);
#endif