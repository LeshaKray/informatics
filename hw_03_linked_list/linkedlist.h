#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
struct list
{
	int value;
	struct list* next;
};
typedef struct list list;
print(list** head);
add_first(list** head, int a);
add_last(list** head, int a);
add_N(list** head, int n, int a);
delete_first(list** head);
delete_last(list** head);
list* get_last(list** head);
#endif