#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
struct list
{
	int value;
	struct list* next;
};
typedef struct list list;
void print(list** head);
void add_first(list** head, int a);
void add_last(list** head, int a);
void add_N(list** head, int n, int a);
void delete_first(list** head);
void delete_last(list** head);
int is_progression(list* head); 
list* get_last(list** head);
#endif