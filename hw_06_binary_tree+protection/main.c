#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "binarytree.h"
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	struct node* root = NULL;
	int menu = -1, value, i;
	while (menu != 0)
	{
		printf("1 - добавление нового элемента в дерево \n");
		printf("2 - обход дерева в ширину \n");
		printf("3 - обход дерева в глубину \n");
		printf("4 - расстояние от корня до элемента \n");
		printf("5 - найти повторяющийся элемент \n");
		printf("0 - Exit \n");
		printf("Выберите пункт: ");
		scanf("%d", &menu);

		if (menu == 1)
		{
			printf("Введите число: ");
			scanf("%d", &value);
			add_new(&root, value);
		}
		else if (menu == 2)
		{
			bfs(root);
		}
		else if (menu == 3)
		{
			dfs(root);
			printf("\n");
		}
		else if (menu == 4)
		{
			printf("Введите число: ");
			scanf("%d", &value);
			search(root, value);
		}
		else if (menu == 5)
		{
			struct node* result = check_repeat(root);

			if (result) {
				printf("Повторяется: %d\n", result->value);
			}
			else {
				printf("Нет повторов\n");
			}
		}
		else
		{
			printf("пункт не корректен \n");
		}
	}
	printf("Программа остановлена\n");
	while (getchar() != '\n');
	getchar();
	return 0;
}