#ifndef _QUEUE_H
#define _QUEUE_H

struct node
{
	float value;
	struct node* next;
	struct node* prev;
};
typedef struct node node;
struct queue
{
	float data;
	struct node* head;
	struct node* tail;
};
typedef struct queue queue;
enqueue(struct queue* queue, const float value);
dequeue(struct queue* queue);
#endif 