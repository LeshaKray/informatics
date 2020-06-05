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
		printf("1 - ������� ������\n");
		printf("2 - �������� � ������\n");
		printf("3 - �������� � �����\n");
		printf("4 - �������� ����� �� ����� N-�� ��������\n");
		printf("5 - ������� ������ �������\n");
		printf("6 - ������� ��������� �������\n");
		printf("7 - ��������� �� �������������� ����������\n");
		printf("0 - �����\n");
		scanf("%d", &menu);

		if (menu == 1)
		{
			if (l == NULL)
				printf("Empty\n");
			else
			{
				printf("������: ");
				print(&l);
				printf("\n");
			}
		}
		else if (menu == 2)
		{
			int b;
			printf("������� �����: ");
			scanf("%d", &b);
			add_first(&l, b);
			printf("������ �������� � ������\n");
		}
		else if (menu == 3)
		{
			int c;
			printf("������� �����: ");
			scanf("%d", &c);
			add_last(&l, c);
			printf("������� �������� � �����\n");
		}
		else if (menu == 4)
		{
			int d, n;
			printf("�������� N � ������� �����: ");
			scanf("%d %d", &n, &d);
			add_N(&l, n, d);
			printf("������� N �������\n");
		}
		else if (menu == 5)
		{
			delete_first(&l);
			printf("�������� ������� ��������\n");
		}
		else if (menu == 6)
		{
			delete_last(&l);
			printf("�������� ���������� ��������\n");
		}
		else if (menu == 7) {
			if (is_progression(l)) {
				printf("������ �������� �������������� �����������\n");
			}
			else {
				printf("������ �� �������� �������������� �����������\n");
			}
		}
		else if (menu == 0)
		{
			printf("\n");
		}
		else
		{
			printf("������������ �����\n");
		}
	}
	printf("��������� �����������\n");
	return 0;
}
