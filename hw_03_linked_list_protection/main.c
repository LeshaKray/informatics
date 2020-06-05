#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include<locale.h>
#include "linkedlist.h"
#include <stdlib.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	int a, menu = -1;
	 list* l= NULL;
	while (menu != 0)
	{
		printf("1 - вывести список\n");
		printf("2 - добавить в начало\n");
		printf("3 - добавить в конец\n");
		printf("4 - дабавить число на место N-го элемента\n");
		printf("5 - удалить первый элемент\n");
		printf("6 - удалить последний элемент\n");
		printf("7 - проверить на арифметическую прогрессию\n");
		printf("0 - выход\n");
		scanf("%d", &menu);

		if (menu == 1)
		{
			if (l == NULL)
				printf("Empty\n");
			else
			{
				printf("Список: ");
				print(&l);
				printf("\n");
			}
		}
		else if (menu == 2)
		{
			int b;
			printf("Введите число: ");
			scanf("%d", &b);
			add_first(&l, b);
			printf("Элемен добавлен в начало\n");
		}
		else if (menu == 3)
		{
			int c;
			printf("Введите число: ");
			scanf("%d", &c);
			add_last(&l, c);
			printf("Элемент добавлен в конец\n");
		}
		else if (menu == 4)
		{
			int d, n;
			printf("Выберите N и введите число: ");
			scanf("%d %d", &n, &d);
			add_N(&l, n, d);
			printf("элемент N изменен\n");
		}
		else if (menu == 5)
		{
			delete_first(&l);
			printf("удаление первого элемента\n");
		}
		else if (menu == 6)
		{
			delete_last(&l);
			printf("удаление последнего элемента\n");
		}
		else if (menu == 7) {
			if (is_progression(l)) {
				printf("список является арифметической прогрессией\n");
			}
			else {
				printf("список не является арифметической прогрессией\n");
			}
		}
		else if (menu == 0)
		{
			printf("\n");
		}
		else
		{
			printf("Неправильный пункт\n");
		}
	}
	printf("Программа остановлена\n");
	return 0;
}
