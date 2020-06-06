#ifndef _BINARYTREE_H
#define _BINARYTREE_H
struct node
{
	int value;
	struct node* left;
	struct node* right;
};
typedef struct node node;
struct queue
{
	struct queue* next;
	struct node* tree;
};
typedef struct queue queue;
void add_new(struct node** root, int value);
void dfs(struct node* node);
void enqueue(struct queue** head, struct queue** tail, struct node* value);
struct node* dequeue(struct queue** head, struct queue** tail);
void bfs(struct node* root);
void search(struct node* root, const int num);
int check_value(struct node* root, int value);
struct node* check_repeat(struct node* root);
#endif 