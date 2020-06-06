#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <locale.h>

moving_average(float* a, int n, int k)
{
	int i = 0;
	float sum = 0;
	int len = 0;
	float value;
	struct queue queue;
	queue.head = NULL;
	queue.tail = NULL;
	struct node* q = NULL;
	enqueue(&queue, a[i]);
	q = queue.head;
	sum += q->value;
	len++;
	printf("%.3f ", sum / len);
	for (i = 1; i < k; i++)
	{
		enqueue(&queue, a[i]);
		q = q->next;
		sum += q->value;
		len++;
		printf("%.3f ", sum / len);
	}
	for (i = k; i < n; i++)
	{
		q = queue.head;
		sum -= q->value;
		dequeue(&queue);
		enqueue(&queue, a[i]);
		q = queue.tail;
		sum += q->value;
		printf("%.3f ", sum / len);
	}
	printf("\n");
}
int main()
{
	setlocale(LC_ALL, "Russian");
		int n, k, i;
	printf("¬ведите количество чисел и длину окна:");
	scanf("%d %d", &n, &k);
	float* a = (float*)malloc(n * sizeof(float));
	for (i = 0; i < n; i++)
		scanf("%f", &a[i]);
	moving_average(a, n, k);
	while (getchar() != '\n');
	getchar();
}