#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"
void enqueue(struct queue** head, struct queue** tail, struct node* value)
{
	struct queue* q = (struct queue*)malloc(sizeof(struct queue));
	q->next = NULL;
	q->tree = value;
	if ((*head == NULL) && (*tail == NULL))
		* head = q;
	else
		(*tail)->next = q;
	*tail = q;
}
struct node* dequeue(struct queue** head, struct queue** tail)
{
	struct node* result;
	result = (*head)->tree;
	struct queue* buf;
	buf = *head;
	*head = (*head)->next;
	if (*head == NULL)
		* tail = NULL;
	free(buf);
	return result;
}

void add_new(struct node** root, int new_value)
{
	if (*root == NULL)
	{
		*root = (struct node*)malloc(sizeof(struct node));
		(*root)->value = new_value;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else
	{
		if (new_value > (*root)->value)
			add_new(&(*root)->right, new_value);
		else
			add_new(&(*root)->left, new_value);
	}
}

void dfs(struct node* root)
{
	if (root == NULL)
	{
		printf("дерево пустое");
		return;
	}
	printf("%d ", root->value);
	if (root->left != NULL)
		dfs(root->left);
	if (root->right != NULL)
		dfs(root->right);
}

void bfs(struct node* root)
{
	struct queue* head;
	struct queue* tail;
	head = NULL;
	tail = NULL;
	enqueue(&head, &tail, root);
	while (head != NULL)
	{
		struct queue* new_head;
		struct queue* new_tail;
		new_head = NULL;
		new_tail = NULL;
		while (head != NULL)
		{
			struct node* value;
			value = dequeue(&head, &tail);
			if (value == NULL)
			{
				printf("дерево пустое\n");
				return;
			}
			if (value->left)
				enqueue(&new_head, &new_tail, value->left);
			if (value->right)
				enqueue(&new_head, &new_tail, value->right);
			printf("%d ", value->value);
		}

		head = new_head;
		tail = new_tail;
		printf("\n");
	}
}

void search(struct node* root, const int num)
{
	int cout = 0;
	struct queue* head;
	struct queue* tail;
	head = NULL;
	tail = NULL;
	enqueue(&head, &tail, root);
	while (head != NULL)
	{
		struct queue* new_head;
		struct queue* new_tail;
		new_head = NULL;
		new_tail = NULL;
		while (head != NULL)
		{
			struct node* value;
			value = dequeue(&head, &tail);
			if (value == NULL)
			{
				printf("дерево пустое\n");
				return;
			}
			if (value->value == num)
			{
				printf("уровень = %d\n", cout);
				return;
			}
			if (value->left)
				enqueue(&new_head, &new_tail, value->left);
			if (value->right)
				enqueue(&new_head, &new_tail, value->right);
		}
		cout++;
		head = new_head;
		tail = new_tail;
	}
	printf("такого числа нет\n");
	return;
}

int check_value(struct node* root, int value) {
	if (root == NULL)
		return 0;

	if (value == root->value)
		return 1;

	if (value > root->value)
		return check_value(root->right, value);

	return check_value(root->left, value);
}

struct node* check_repeat(struct node* root) {
	if (root == NULL)
		return NULL;

	if (check_value(root->left, root->value))
		return root;

	struct node* left = check_repeat(root->left);
	struct node* right = check_repeat(root->right);

	return left ? left : right;
}