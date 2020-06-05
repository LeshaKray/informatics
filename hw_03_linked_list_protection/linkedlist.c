#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include "linkedlist.h"
#include <stdlib.h>
void print(list** head)
{
	list* l = *head;
	while (l != NULL)
	{
		printf("%d ", l->value);
		l = l->next;
	}
}

void add_first(list** head, int a)
{
	list* l = (list*)malloc(sizeof(list));
	l->value = a;
	l->next = *head;
	*head = l;
}
void add_last(list** head, int a)
{
	list* l = get_last(head);
	list* l1 = (list*)malloc(sizeof(list));
	l1->value = a;
	l1->next = NULL;
	l->next = l1;
}
void add_N(list** head, int n, int a)
{
	int k;
	int counter = 0;
	list* l1 = *head;
	list* next = *head;
	list* prev = *head;
	if (n == 1)
	{
		list* l = (list*)malloc(sizeof(list));
		l->value = a;
		l->next = *head;
		*head = l;
	}
	else
	{
		while (l1 != NULL)
		{
			l1 = l1->next;
			counter++;
		}
		if (counter == 0)
		{
			list* l = (list*)malloc(sizeof(list));
			l->value = a;
			l->next = *head;
			*head = l;
		}
		else if (counter < n)
		{
			printf(" Ваш номер больше числа элементов\n");
		}
		else
		{
			n--;
			k = n;
			k--;
			while (n != 0)
			{
				next = next->next;
				n--;
			}
			while (k != 0)
			{
				prev = prev->next;
				k--;
			}
			list* l = (list*)malloc(sizeof(list));
			l->value = a;
			l->next = next;
			prev->next = l;
		}
	}

}
void delete_first(list** head)
{
	list* prev = NULL;
	int val;
	prev = (*head);
	val = prev->value;
	(*head) = (*head)->next;
	free(prev);
}
void delete_last(list** head)
{
	int a = 0;
	list* l = *head;
	list* buf = *head;
	while (l != NULL)
	{
		l = l->next;
		a++;
	}
	if (a == 1)
	{
		*head = NULL;
	}
	else
	{
		a = a - 2;
		while (a != 0)
		{
			buf = buf->next;
			a--;
		}
		buf->next = NULL;
	}
}
list* get_last(list** head)
{
	list* l = *head;
	while (l->next)
	{
		l = l->next;
	}
	return (l);
}

int is_progression(list* head) {
	if (head == NULL)
		return 0;

	if (head->next == NULL)
		return 0; 

	int d = head->next->value - head->value;

	list* node = head;

	while (node->next->next) {
		if (node->next->value - node->value != d) 
			return 0; 

		node = node->next;
	}

	return 1; 
}