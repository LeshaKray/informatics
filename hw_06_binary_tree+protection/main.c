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
		printf("1 - ���������� ������ �������� � ������ \n");
		printf("2 - ����� ������ � ������ \n");
		printf("3 - ����� ������ � ������� \n");
		printf("4 - ���������� �� ����� �� �������� \n");
		printf("5 - ����� ������������� ������� \n");
		printf("0 - Exit \n");
		printf("�������� �����: ");
		scanf("%d", &menu);

		if (menu == 1)
		{
			printf("������� �����: ");
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
			printf("������� �����: ");
			scanf("%d", &value);
			search(root, value);
		}
		else if (menu == 5)
		{
			struct node* result = check_repeat(root);

			if (result) {
				printf("�����������: %d\n", result->value);
			}
			else {
				printf("��� ��������\n");
			}
		}
		else
		{
			printf("����� �� ��������� \n");
		}
	}
	printf("��������� �����������\n");
	while (getchar() != '\n');
	getchar();
	return 0;
}