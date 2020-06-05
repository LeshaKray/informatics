#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	int* main = NULL;
	int* store = NULL;
	int* buffer = NULL;
	int n, m, s = 10, k, i, j, counter = 0, ring = 0, a = 0;
	printf("¬ведите размер массива: ");
	scanf("%d %d", &n, &m);
	main = (int*)malloc(n * m * sizeof(int));
	store = (int*)malloc(s * sizeof(int));
	printf("¬ведите числа которыми будет заполнен массив: ");
	for (i = 0; i < s; i++)
		scanf("%d", &store[i]);
	buffer = (int*)realloc(store, n * m * sizeof(int));
	store = buffer;
	k = s;
	s = n * m;
	if (n * m > k)
		for (i = k; i < s; i++)
		{
			if (a < k - 1)
			{
				store[i] = store[i - 1] - 1;
				a++;
			}
			else
			{
				store[i] = store[i - 1] + 1;
				a++;
			}
			if (a == 2 * k - 2)
				a = 0;
		}
	while (counter < s)
	{
		if (counter >= s) break;
		for (i = ring; i < m - ring; i++)
		{
			*(main + ring * m + i) = store[counter];
			counter++;
		}
		if (counter >= s) break;
		for (i = ring + 1; i < n - ring; i++)
		{
			*(main + i * m + m - ring - 1) = store[counter];
			counter++;
		}
		if (counter >= s) break;
		for (i = m - ring - 1; i > ring; i--)
		{
			*(main + (n - ring - 1) * m + i - 1) = store[counter];
			counter++;
		}
		if (counter >= s) break;
		for (i = n - ring - 2; i > ring; i--)
		{
			*(main + i * m + ring) = store[counter];
			counter++;
		}
		ring++;
	}
	printf("\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			printf("%d ", *(main + i * m + j));
		printf("\n");
	}
	free(main);
	free(store);
	while (getchar() != '\n');
	getchar();
	return 0;
}